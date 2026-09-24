#include <stdio.h>
#include <string.h>

int main(void)
{
    char source[] = "Hello";
    char destination[20];

    memcpy(destination, source, sizeof(source));

    printf("After memcpy: %s\n", destination);

    char data[] = "ABCDE";

    memmove(data + 1, data, 4);

    printf("After memmove: %s\n", data);

    return 0;
}
