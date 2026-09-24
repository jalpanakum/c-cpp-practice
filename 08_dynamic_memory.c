#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *numbers;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    numbers = malloc(n * sizeof(int));

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

    printf("Numbers are:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    free(numbers);
    numbers = NULL;

    return 0;
}
