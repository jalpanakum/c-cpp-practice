#include <stdio.h>

int global_count = 10;

static void increment_count(void)
{
    static int local_count = 0;

    local_count++;
    global_count++;

    printf("Local count: %d\n", local_count);
    printf("Global count: %d\n", global_count);
}

int main(void)
{
    extern int global_count;

    printf("Initial global count: %d\n", global_count);

    increment_count();
    increment_count();
    increment_count();

    return 0;
}
