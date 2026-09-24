#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define MY_IOCTL_CMD 0x1234

int main(void)
{
    int result;

    result = ioctl(STDOUT_FILENO, MY_IOCTL_CMD, NULL);

    if (result == -1)
    {
        perror("ioctl");
        return 1;
    }

    printf("ioctl command executed successfully\n");

    return 0;
}
