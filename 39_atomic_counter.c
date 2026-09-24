#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

#define ITERATIONS 100000

atomic_int counter = 0;

void *increment_counter(void *arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        atomic_fetch_add(&counter, 1);
    }

    return NULL;
}

int main(void)
{
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final counter: %d\n", atomic_load(&counter));

    return 0;
}
