#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *worker(void *arg)
{
    printf("Worker thread started\n");

    sleep(2);

    printf("Worker thread finished\n");

    return NULL;
}

int main(void)
{
    pthread_t thread;

    pthread_create(&thread, NULL, worker, NULL);

    pthread_detach(thread);

    printf("Main thread continues\n");

    sleep(3);

    printf("Main thread finished\n");

    return 0;
}
