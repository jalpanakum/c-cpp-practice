#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <poll.h>

int main(void)
{
    struct pollfd fds[2];
    char buffer[100];

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    fds[1].fd = STDOUT_FILENO;
    fds[1].events = POLLOUT;

    printf("Waiting for keyboard input...\n");

    int result = poll(fds, 2, 5000);

    if (result < 0)
    {
        perror("poll");
        return 1;
    }

    if (result == 0)
    {
        printf("Timeout: No activity within 5 seconds.\n");
        return 0;
    }

    if (fds[0].revents & POLLIN)
    {
        int bytes_read = read(STDIN_FILENO,
                              buffer,
                              sizeof(buffer) - 1);

        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0';
            printf("Input received: %s\n", buffer);
        }
    }

    if (fds[1].revents & POLLOUT)
    {
        printf("Standard output is ready.\n");
    }

    return 0;
}
