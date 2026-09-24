#include <stdio.h>

int main(void)
{
    FILE *file;
    char data[100];

    file = fopen("data.txt", "w");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(file, "Hello, Jalpa!\n");
    fprintf(file, "This is a C file handling example.\n");

    fclose(file);

    file = fopen("data.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("File contents:\n");

    while (fgets(data, sizeof(data), file) != NULL)
    {
        printf("%s", data);
    }

    fclose(file);

    return 0;
}
