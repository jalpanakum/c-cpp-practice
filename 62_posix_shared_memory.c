#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    const char *name = "/my_shared_memory";
    const char *message = "Hello from shared memory";

    int fd;
    char *ptr;

    fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    if (fd == -1)
    {
        perror("shm_open");
        return 1;
    }

    if (ftruncate(fd, 100) == -1)
    {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    ptr = mmap(NULL, 100,
               PROT_READ | PROT_WRITE,
               MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    strcpy(ptr, message);

    printf("Shared memory contains: %s\n", ptr);

    munmap(ptr, 100);
    close(fd);

    shm_unlink(name);

    return 0;
}
