#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main(void)
{
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd == -1)
    {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0)
    {
        perror("inet_pton");
        close(sock_fd);
        return 1;
    }

    if (connect(sock_fd,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) == -1)
    {
        perror("connect");
        close(sock_fd);
        return 1;
    }

    printf("Connected to server.\n");
    printf("Type a message (type 'exit' to quit):\n");

    while (1)
    {
        printf("Client: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            break;
        }

        if (strncmp(buffer, "exit", 4) == 0)
        {
            break;
        }

        if (send(sock_fd, buffer, strlen(buffer), 0) == -1)
        {
            perror("send");
            break;
        }

        memset(buffer, 0, sizeof(buffer));

        int bytes = recv(sock_fd, buffer, sizeof(buffer) - 1, 0);

        if (bytes <= 0)
        {
            printf("Server disconnected.\n");
            break;
        }

        buffer[bytes] = '\0';

        printf("Server: %s", buffer);
    }

    close(sock_fd);

    printf("Client disconnected.\n");

    return 0;
}
