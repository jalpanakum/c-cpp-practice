#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    int fd;

    fd = open("does_not_exist.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("open() failed\n");
        printf("errno = %d\n", errno);
        printf("Error message: %s\n", strerror(errno));

        perror("open");
        return 1;
    }

    close(fd);

    return 0;
}
