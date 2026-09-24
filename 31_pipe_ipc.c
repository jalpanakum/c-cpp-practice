#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    int pipe_fd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        close(pipe_fd[1]);

        read(pipe_fd[0], buffer, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';

        printf("Child received: %s\n", buffer);

        close(pipe_fd[0]);
    }
    else
    {
        close(pipe_fd[0]);

        write(pipe_fd[1], message, strlen(message) + 1);

        close(pipe_fd[1]);

        wait(NULL);

        printf("Parent process completed.\n");
    }

    return 0;
}
