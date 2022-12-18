#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct circularQueue
{
    int rear;
    int front;
    int max_size;
    int arr[5];
};

int empty(struct circularQueue *q)
{
    if (q->front == -1)
    {
        return -1;
    }
    return 0;
}

int full(struct circularQueue *q)
{
    if ((q->rear + 1) % q->max_size == q->front)
    {
        return -1;
    }
    return 0;
}

int enqueue(struct circularQueue *q, int item)
{
    if (full(q))
    {
        printf("Cannot enqueue ! queue is full\n");
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % q->max_size;
    q->arr[q->rear] = item;
    printf("Enqueued: %d\n", item);
    return 0;
}

void dequeue(struct circularQueue *q)
{
    if (empty(q))
    {
        printf("Exception! Queue empty\n");
    }
    int result = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->max_size;
    }
    printf("Dequeued: %d\n", result);
}

// Display the queue
void display(struct circularQueue *q)
{
    int i;
    if (empty(q))
        printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ", q->front);
        printf("\n Items -> ");
        for (i = q->front; i != q->rear; i = (i + 1) % q->max_size)
        {
            printf("%d ", q->arr[i]);
        }
        printf("%d ", q->arr[i]);
        printf("\n Rear -> %d \n", q->rear);
    }
}

int main()
{
    struct circularQueue *q;
    int choice, item;
    bool condition = true;
    q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q->rear = -1;
    q->front = -1;
    q->max_size = 5;

// for the condition
done:
    printf("Enter 1. for enqueue: \n");
    printf("Enter 2. for dequeue: \n");
    printf("Enter 3. for peeking elements: \n");
    printf("Enter 4. to exit: \n");
    scanf("%d", &choice);
    // until condition is satisfied
    while (condition)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the item to insert? ");
            scanf("%d", &item);
            enqueue(q, item);
            goto done;

        case 2:
            dequeue(q);
            goto done;
            break;

        case 3:
            display(q);
            goto done;
            break;

        case 4:
            condition = false;
            break;

        default:
            printf("Please enter valid value!");
            condition = false;
        }
    }

    return 0;
}
