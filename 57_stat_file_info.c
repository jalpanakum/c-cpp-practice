#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
    struct stat file_info;

    if (stat("data.txt", &file_info) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("File size: %ld bytes\n", file_info.st_size);
    printf("File permissions: %o\n", file_info.st_mode & 0777);
    printf("Number of hard links: %ld\n", file_info.st_nlink);

    return 0;
}
