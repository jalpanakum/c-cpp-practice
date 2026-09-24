#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *worker(void *arg)
{
    int i;

    for (i = 1; i <= 10; i++)
    {
        printf("Worker: %d\n", i);
        sleep(1);
    }

    return NULL;
}

int main(void)
{
    pthread_t thread;

    pthread_create(&thread, NULL, worker, NULL);

    sleep(3);

    printf("Main: Cancelling worker thread\n");

    pthread_cancel(thread);

    pthread_join(thread, NULL);

    printf("Main: Worker thread cancelled\n");

    return 0;
}
