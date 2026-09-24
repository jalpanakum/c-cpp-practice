#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(void)
{
    int server_fd;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_length = sizeof(client_address);
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);

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

    printf("UDP server waiting for data...\n");

    memset(buffer, 0, sizeof(buffer));

    int bytes_received = recvfrom(server_fd,
                                  buffer,
                                  sizeof(buffer) - 1,
                                  0,
                                  (struct sockaddr *)&client_address,
                                  &client_length);

    if (bytes_received < 0)
    {
        perror("recvfrom");
        close(server_fd);
        return 1;
    }

    buffer[bytes_received] = '\0';

    printf("Client: %s\n", buffer);

    sendto(server_fd,
           buffer,
           bytes_received,
           0,
           (struct sockaddr *)&client_address,
           client_length);

    close(server_fd);

    return 0;
}
