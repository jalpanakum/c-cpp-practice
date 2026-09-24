#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(void)
{
    int shmid;
    char *shared_memory;

    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1)
    {
        perror("shmget");
        return 1;
    }

    shared_memory = (char *)shmat(shmid, NULL, 0);

    if (shared_memory == (char *)-1)
    {
        perror("shmat");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        strcpy(shared_memory, "Hello from child process!");

        printf("Child: Data written to shared memory.\n");

        shmdt(shared_memory);

        return 0;
    }
    else
    {
        wait(NULL);

        printf("Parent: Data received: %s\n", shared_memory);

        shmdt(shared_memory);

        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
