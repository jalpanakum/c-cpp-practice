#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal_number)
{
    if (signal_number == SIGINT)
    {
        printf("\nSIGINT received.\n");
        printf("Program is exiting safely.\n");
        _exit(0);
    }
}

int main(void)
{
    signal(SIGINT, signal_handler);

    printf("Program is running.\n");
    printf("Press Ctrl+C to send SIGINT.\n");

    while (1)
    {
        printf("Waiting for signal...\n");
        sleep(2);
    }

    return 0;
}
