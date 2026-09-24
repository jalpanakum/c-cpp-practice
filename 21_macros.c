#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    int number = 5;
    int a = 10;
    int b = 20;

    printf("PI = %.5f\n", PI);
    printf("Square of %d = %d\n", number, SQUARE(number));
    printf("Maximum = %d\n", MAX(a, b));

    return 0;
}
