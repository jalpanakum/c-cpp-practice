#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal_number)
{
    if (signal_number == SIGINT)
    {
        printf("\nSIGINT received. Program is still running.\n");
    }
}

int main(void)
{
    struct sigaction action;

    action.sa_handler = handle_signal;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if (sigaction(SIGINT, &action, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    printf("Program is running. Press Ctrl+C...\n");

    while (1)
    {
        sleep(1);
    }

    return 0;
}
