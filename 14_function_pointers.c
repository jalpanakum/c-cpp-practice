#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int calculate(int a, int b, int (*operation)(int, int))
{
    return operation(a, b);
}

int main(void)
{
    int result;

    result = calculate(10, 5, add);
    printf("Addition: %d\n", result);

    result = calculate(10, 5, multiply);
    printf("Multiplication: %d\n", result);

    return 0;
}
