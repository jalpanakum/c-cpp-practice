#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_key_t key;

void *worker(void *arg)
{
    int id = *(int *)arg;

    int *data = (int *)pthread_getspecific(key);

    if (data == NULL)
    {
        data = malloc(sizeof(int));
    }

    *data = id * 100;

    pthread_setspecific(key, data);

    printf("Thread %d: Thread-specific data = %d\n", id, *data);

    free(data);

    return NULL;
}

int main(void)
{
    pthread_t thread1, thread2;

    int id1 = 1;
    int id2 = 2;

    pthread_key_create(&key, NULL);

    pthread_create(&thread1, NULL, worker, &id1);
    pthread_create(&thread2, NULL, worker, &id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_key_delete(key);

    return 0;
}
