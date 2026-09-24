#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[50];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s!\n", name);
    printf("Length of your name: %zu\n", strlen(name));

    return 0;
}
