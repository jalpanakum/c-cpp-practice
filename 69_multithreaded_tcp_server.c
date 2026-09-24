#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg)
{
    int client_fd = *(int *)arg;
    char buffer[BUFFER_SIZE];

    free(arg);

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));

        int bytes = recv(client_fd, buffer, sizeof(buffer) - 1, 0);

        if (bytes <= 0)
        {
            break;
        }

        printf("Client: %s", buffer);

        send(client_fd, buffer, bytes, 0);
    }

    close(client_fd);

    printf("Client disconnected\n");

    return NULL;
}

int main(void)
{
    int server_fd;
    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1)
    {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) == -1)
    {
        perror("bind");
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 5) == -1)
    {
        perror("listen");
        close(server_fd);
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    while (1)
    {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int *client_fd = malloc(sizeof(int));

        if (client_fd == NULL)
        {
            perror("malloc");
            continue;
        }

        *client_fd = accept(server_fd,
                            (struct sockaddr *)&client_addr,
                            &client_len);

        if (*client_fd == -1)
        {
            perror("accept");
            free(client_fd);
            continue;
        }

        printf("Client connected\n");

        pthread_t thread;

        if (pthread_create(&thread, NULL,
                           handle_client, client_fd) != 0)
        {
            perror("pthread_create");
            close(*client_fd);
            free(client_fd);
            continue;
        }

        pthread_detach(thread);
    }

    close(server_fd);

    return 0;
}
