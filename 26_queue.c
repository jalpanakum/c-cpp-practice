#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full.\n");
        return;
    }

    queue[++rear] = value;
}

void dequeue(void)
{
    if (front > rear)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Dequeued: %d\n", queue[front++]);
}

void display(void)
{
    if (front > rear)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}
