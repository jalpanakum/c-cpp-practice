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
    const char *message = "Hello UDP Server";

    client_fd = socket(AF_INET, SOCK_DGRAM, 0);

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

    sendto(client_fd,
           message,
           strlen(message),
           0,
           (struct sockaddr *)&server_address,
           sizeof(server_address));

    printf("Message sent: %s\n", message);

    memset(buffer, 0, sizeof(buffer));

    socklen_t server_length = sizeof(server_address);

    int bytes_received = recvfrom(client_fd,
                                  buffer,
                                  sizeof(buffer) - 1,
                                  0,
                                  (struct sockaddr *)&server_address,
                                  &server_length);

    if (bytes_received < 0)
    {
        perror("recvfrom");
        close(client_fd);
        return 1;
    }

    buffer[bytes_received] = '\0';

    printf("Server response: %s\n", buffer);

    close(client_fd);

    return 0;
}
