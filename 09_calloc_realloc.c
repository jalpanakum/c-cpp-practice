#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int new_size;
    int *numbers;

    printf("Enter initial number of elements: ");
    scanf("%d", &n);

    numbers = calloc(n, sizeof(int));

    if (numbers == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("Initial numbers:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    printf("Enter new size: ");
    scanf("%d", &new_size);

    int *temp = realloc(numbers, new_size * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(numbers);
        return 1;
    }

    numbers = temp;

    if (new_size > n)
    {
        printf("Enter %d additional numbers:\n", new_size - n);

        for (int i = n; i < new_size; i++)
        {
            scanf("%d", &numbers[i]);
        }
    }

    printf("Final numbers:\n");

    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    free(numbers);
    numbers = NULL;

    return 0;
}
