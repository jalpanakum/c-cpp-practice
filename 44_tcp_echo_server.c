#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(void)
{
    int client_fd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (client_fd < 0)
    {
        perror("socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1",
                  &server_address.sin_addr) <= 0)
    {
        perror("inet_pton");
        close(client_fd);
        return 1;
    }

    if (connect(client_fd,
                (struct sockaddr *)&server_address,
                sizeof(server_address)) < 0)
    {
        perror("connect");
        close(client_fd);
        return 1;
    }

    printf("Connected to server.\n");

    while (1)
    {
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        send(client_fd, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit") == 0)
        {
            break;
        }

        memset(buffer, 0, sizeof(buffer));

        int bytes_received = recv(client_fd,
                                  buffer,
                                  sizeof(buffer) - 1,
                                  0);

        if (bytes_received <= 0)
        {
            printf("Server disconnected.\n");
            break;
        }

        buffer[bytes_received] = '\0';

        printf("Server echoed: %s\n", buffer);
    }

    close(client_fd);

    return 0;
}
