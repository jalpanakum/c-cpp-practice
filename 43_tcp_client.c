#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(void)
{
    int client_fd;
    struct sockaddr_in server_address;
    const char *message = "Hello Server";

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

    if (send(client_fd,
             message,
             strlen(message),
             0) < 0)
    {
        perror("send");
    }
    else
    {
        printf("Message sent: %s\n", message);
    }

    close(client_fd);

    return 0;
}
