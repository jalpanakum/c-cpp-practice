#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    const char *filename = "mmap_data.txt";
    const char *message = "Hello from mmap!\n";

    int fd;
    struct stat file_info;
    char *mapped;

    fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (ftruncate(fd, 100) == -1)
    {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    if (fstat(fd, &file_info) == -1)
    {
        perror("fstat");
        close(fd);
        return 1;
    }

    mapped = mmap(NULL,
                  file_info.st_size,
                  PROT_READ | PROT_WRITE,
                  MAP_SHARED,
                  fd,
                  0);

    if (mapped == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    strcpy(mapped, message);

    printf("Mapped memory contains: %s", mapped);

    munmap(mapped, file_info.st_size);
    close(fd);

    return 0;
}
