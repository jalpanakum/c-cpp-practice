#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>

#define MESSAGE_SIZE 100

struct message
{
    long message_type;
    char message_text[MESSAGE_SIZE];
};

int main(void)
{
    int msgid;
    struct message msg;

    msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);

    if (msgid == -1)
    {
        perror("msgget");
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
        msg.message_type = 1;
        strcpy(msg.message_text, "Hello from child process!");

        if (msgsnd(msgid, &msg, strlen(msg.message_text) + 1, 0) == -1)
        {
            perror("msgsnd");
            return 1;
        }

        printf("Child: Message sent.\n");

        return 0;
    }
    else
    {
        wait(NULL);

        if (msgrcv(msgid, &msg, MESSAGE_SIZE, 1, 0) == -1)
        {
            perror("msgrcv");
            return 1;
        }

        printf("Parent: Message received: %s\n", msg.message_text);

        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
