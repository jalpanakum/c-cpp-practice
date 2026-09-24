#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10

int main(void)
{
    int epoll_fd;
    struct epoll_event event;
    struct epoll_event events[MAX_EVENTS];

    epoll_fd = epoll_create1(0);

    if (epoll_fd == -1)
    {
        perror("epoll_create1");
        return 1;
    }

    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;

    if (epoll_ctl(epoll_fd,
                  EPOLL_CTL_ADD,
                  STDIN_FILENO,
                  &event) == -1)
    {
        perror("epoll_ctl");
        close(epoll_fd);
        return 1;
    }

    printf("Waiting for keyboard input...\n");

    int count = epoll_wait(epoll_fd,
                           events,
                           MAX_EVENTS,
                           5000);

    if (count == -1)
    {
        perror("epoll_wait");
        close(epoll_fd);
        return 1;
    }

    if (count == 0)
    {
        printf("Timeout: No input received.\n");
    }
    else
    {
        printf("Input is ready for reading.\n");
    }

    close(epoll_fd);

    return 0;
}
