#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed.\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child process started.\n");
        printf("Child PID: %d\n", getpid());

        sleep(2);

        printf("Child process completed.\n");
    }
    else
    {
        printf("Parent waiting for child...\n");

        wait(&status);

        printf("Child process finished.\n");
        printf("Parent process completed.\n");
    }

    return 0;
}
