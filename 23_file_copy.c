#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *source;
    FILE *destination;
    char buffer[1024];
    size_t bytes_read;

    if (argc != 3)
    {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    source = fopen(argv[1], "rb");

    if (source == NULL)
    {
        printf("Unable to open source file.\n");
        return 1;
    }

    destination = fopen(argv[2], "wb");

    if (destination == NULL)
    {
        printf("Unable to open destination file.\n");
        fclose(source);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0)
    {
        fwrite(buffer, 1, bytes_read, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");

    return 0;
}
