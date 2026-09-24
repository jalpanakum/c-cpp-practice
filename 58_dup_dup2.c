#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    int new_fd;

    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    new_fd = dup(fd);

    if (new_fd == -1)
    {
        perror("dup");
        close(fd);
        return 1;
    }

    write(fd, "Hello using original FD\n", 24);
    write(new_fd, "Hello using duplicated FD\n", 26);

    printf("Original FD: %d\n", fd);
    printf("Duplicated FD: %d\n", new_fd);

    close(fd);
    close(new_fd);

    return 0;
}
