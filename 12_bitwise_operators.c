#include <stdio.h>

int main(void)
{
    unsigned int a = 14;  // Binary: 1110
    unsigned int b = 12;  // Binary: 1100

    printf("a & b = %u\n", a & b);
    printf("a | b = %u\n", a | b);
    printf("a ^ b = %u\n", a ^ b);
    printf("~a = %u\n", ~a);
    printf("a << 1 = %u\n", a << 1);
    printf("a >> 1 = %u\n", a >> 1);

    return 0;
}
