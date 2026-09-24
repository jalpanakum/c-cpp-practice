#include <stdio.h>

int main(void)
{
    int num = 10;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void *)&num);
    printf("Value using pointer: %d\n", *ptr);

    *ptr = 20;

    printf("Updated value of num: %d\n", num);

    return 0;
}
