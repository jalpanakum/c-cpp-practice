#include <stdio.h>

int main(void)
{
    const int max_value = 100;
    volatile int hardware_value = 0;

    printf("Maximum value: %d\n", max_value);

    hardware_value = 10;
    printf("Hardware value: %d\n", hardware_value);

    hardware_value = 20;
    printf("Hardware value: %d\n", hardware_value);

    return 0;
}
