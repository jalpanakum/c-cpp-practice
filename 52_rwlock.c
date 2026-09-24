#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_data = 100;

pthread_rwlock_t rwlock;

void *reader(void *arg)
{
    int id = *(int *)arg;

    pthread_rwlock_rdlock(&rwlock);

    printf("Reader %d: Reading data = %d\n", id, shared_data);

    sleep(1);

    pthread_rwlock_unlock(&rwlock);

    return NULL;
}

void *writer(void *arg)
{
    pthread_rwlock_wrlock(&rwlock);

    shared_data++;

    printf("Writer: Updated data = %d\n", shared_data);

    sleep(1);

    pthread_rwlock_unlock(&rwlock);

    return NULL;
}

int main(void)
{
    pthread_t reader1;
    pthread_t reader2;
    pthread_t writer1;

    int id1 = 1;
    int id2 = 2;

    pthread_rwlock_init(&rwlock, NULL);

    pthread_create(&reader1, NULL, reader, &id1);
    pthread_create(&reader2, NULL, reader, &id2);

    pthread_join(reader1, NULL);
    pthread_join(reader2, NULL);

    pthread_create(&writer1, NULL, writer, NULL);

    pthread_join(writer1, NULL);

    pthread_rwlock_destroy(&rwlock);

    return 0;
}
