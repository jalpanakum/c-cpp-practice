#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(void)
{
    const char *fifo = "myfifo";
    char buffer[100];

    mkfifo(fifo, 0666);

    printf("Waiting for a writer...\n");

    int fd = open(fifo, O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int bytes = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[bytes] = '\0';

    printf("Received: %s\n", buffer);

    close(fd);
    unlink(fifo);

    return 0;
}
