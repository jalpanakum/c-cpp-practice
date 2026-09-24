#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};

    int *ptr = numbers;

    printf("First value: %d\n", *ptr);

    ptr++;
    printf("Second value: %d\n", *ptr);

    ptr++;
    printf("Third value: %d\n", *ptr);

    printf("\nUsing array indexing:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("numbers[%d] = %d\n", i, *(numbers + i));
    }

    return 0;
}
