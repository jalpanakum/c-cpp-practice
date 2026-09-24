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

        execlp("ls", "ls", "-l", NULL);

        printf("exec failed.\n");
        return 1;
    }
    else
    {
        wait(&status);
        printf("Child process completed.\n");
    }

    return 0;
}
