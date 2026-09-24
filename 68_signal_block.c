#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal_number)
{
    printf("\nSIGINT received\n");
}

int main(void)
{
    sigset_t set;

    signal(SIGINT, handle_signal);

    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    printf("Blocking SIGINT for 10 seconds...\n");

    sigprocmask(SIG_BLOCK, &set, NULL);

    for (int i = 1; i <= 10; i++)
    {
        printf("Running: %d\n", i);
        sleep(1);
    }

    printf("Unblocking SIGINT...\n");

    sigprocmask(SIG_UNBLOCK, &set, NULL);

    sleep(2);

    return 0;
}
