#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(void)
{
    int server_fd;
    int client_fd;
    int max_fd;
    int activity;

    struct sockaddr_in server_address;

    fd_set read_fds;

    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_fd,
             (struct sockaddr *)&server_address,
             sizeof(server_address)) < 0)
    {
        perror("bind");
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 5) < 0)
    {
        perror("listen");
        close(server_fd);
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    FD_ZERO(&read_fds);
    FD_SET(server_fd, &read_fds);

    max_fd = server_fd;

    while (1)
    {
        fd_set temp_fds = read_fds;

        activity = select(max_fd + 1, &temp_fds, NULL, NULL, NULL);

        if (activity < 0)
        {
            perror("select");
            break;
        }

        if (FD_ISSET(server_fd, &temp_fds))
        {
            client_fd = accept(server_fd, NULL, NULL);

            if (client_fd < 0)
            {
                perror("accept");
                continue;
            }

            printf("New client connected.\n");

            FD_SET(client_fd, &read_fds);

            if (client_fd > max_fd)
            {
                max_fd = client_fd;
            }
        }

        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (fd != server_fd && FD_ISSET(fd, &temp_fds))
            {
                memset(buffer, 0, sizeof(buffer));

                int bytes_received = recv(fd,
                                          buffer,
                                          sizeof(buffer) - 1,
                                          0);

                if (bytes_received <= 0)
                {
                    printf("Client disconnected.\n");

                    close(fd);
                    FD_CLR(fd, &read_fds);
                }
                else
                {
                    buffer[bytes_received] = '\0';

                    printf("Received: %s\n", buffer);

                    send(fd, buffer, bytes_received, 0);
                }
            }
        }
    }

    close(server_fd);

    return 0;
}
