#include <stdio.h>
#define MAX_SIZE 5

struct queue
{
    int size;
    int rear;
    int front;
    int arr[5];
};

void isEmpty()
{
    struct queue q;
    if (q.rear == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue is full\n");
    }
}

void enqueue(struct queue q, int item)
{
}

int main()
{
    int ch;
    struct queue q;
    printf("Enter 1 to enqueue queue ? \n");
    printf("Enter 2 to dequeue queue ? \n");
    printf("Enter 3 to Display the time ? \n");
    printf("Enter 4 to exit the program ? \n");

    switch (ch)
    {
    case 1:
        enqueue();
        break;
    }

    return 0;
}