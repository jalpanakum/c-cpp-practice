#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void *thread_function(void *arg)
{
    int id = *(int *)arg;

    printf("Thread %d is waiting for the resource.\n", id);

    sem_wait(&semaphore);

    printf("Thread %d acquired the resource.\n", id);

    sleep(2);

    printf("Thread %d released the resource.\n", id);

    sem_post(&semaphore);

    return NULL;
}

int main(void)
{
    pthread_t thread1, thread2, thread3;

    int id1 = 1;
    int id2 = 2;
    int id3 = 3;

    sem_init(&semaphore, 0, 2);

    pthread_create(&thread1, NULL, thread_function, &id1);
    pthread_create(&thread2, NULL, thread_function, &id2);
    pthread_create(&thread3, NULL, thread_function, &id3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    sem_destroy(&semaphore);

    return 0;
}
