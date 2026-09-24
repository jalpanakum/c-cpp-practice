#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd;
    char buffer[100];
    const char *message = "Hello from Linux system calls\n";

    fd = open("data.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, message, strlen(message));

    lseek(fd, 0, SEEK_SET);

    int bytes = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[bytes] = '\0';

    printf("File content: %s", buffer);

    close(fd);

    return 0;
}
