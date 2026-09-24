#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main(void)
{
    const char *queue_name = "/my_queue";

    struct mq_attr attr;
    mqd_t mq;
    char buffer[100];

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 100;
    attr.mq_curmsgs = 0;

    mq = mq_open(queue_name, O_CREAT | O_RDWR, 0644, &attr);

    if (mq == (mqd_t)-1)
    {
        perror("mq_open");
        return 1;
    }

    const char *message = "Hello from message queue";

    if (mq_send(mq, message, strlen(message) + 1, 0) == -1)
    {
        perror("mq_send");
        mq_close(mq);
        mq_unlink(queue_name);
        return 1;
    }

    if (mq_receive(mq, buffer, sizeof(buffer), NULL) == -1)
    {
        perror("mq_receive");
        mq_close(mq);
        mq_unlink(queue_name);
        return 1;
    }

    printf("Received: %s\n", buffer);

    mq_close(mq);
    mq_unlink(queue_name);

    return 0;
}
