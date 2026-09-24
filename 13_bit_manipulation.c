#include <stdio.h>

#define SET_BIT(value, bit)       ((value) |= (1U << (bit)))
#define CLEAR_BIT(value, bit)     ((value) &= ~(1U << (bit)))
#define TOGGLE_BIT(value, bit)    ((value) ^= (1U << (bit)))
#define CHECK_BIT(value, bit)     (((value) >> (bit)) & 1U)

int main(void)
{
    unsigned int value = 0;

    printf("Initial value: %u\n", value);

    SET_BIT(value, 2);
    printf("After setting bit 2: %u\n", value);

    SET_BIT(value, 4);
    printf("After setting bit 4: %u\n", value);

    CLEAR_BIT(value, 2);
    printf("After clearing bit 2: %u\n", value);

    TOGGLE_BIT(value, 4);
    printf("After toggling bit 4: %u\n", value);

    if (CHECK_BIT(value, 4))
    {
        printf("Bit 4 is set.\n");
    }
    else
    {
        printf("Bit 4 is clear.\n");
    }

    return 0;
}
