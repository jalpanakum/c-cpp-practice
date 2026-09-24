#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
    int flags;
    char buffer[100];

    flags = fcntl(STDIN_FILENO, F_GETFL, 0);

    if (flags == -1)
    {
        perror("fcntl");
        return 1;
    }

    if (fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK) == -1)
    {
        perror("fcntl");
        return 1;
    }

    printf("Non-blocking input enabled.\n");
    printf("Try typing something:\n");

    for (int i = 0; i < 10; i++)
    {
        int bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0';
            printf("Received: %s\n", buffer);
            break;
        }
        else if (bytes_read == -1 && errno == EAGAIN)
        {
            printf("No data available. Continuing...\n");
        }
        else if (bytes_read == -1)
        {
            perror("read");
            break;
        }

        sleep(1);
    }

    return 0;
}
