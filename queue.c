#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 5
struct queue
{
    int max_size;
    int arr[size];
    int front;
    int rear;
};

int isfull(struct queue *q)
{
    if (q->rear == q->max_size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int item)
{
    if (isfull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        ++q->rear;
        q->arr[q->rear] = item;
        printf("inserted = %d\n", item);
    }
}
void dequeue(struct queue *q)
{
    if (q->rear == q->front)
    {
        printf("Queue empty ! nothing to dequeue\n");
    }
    else
    {
        q->front++;
        int removedItem = q->arr[q->front];
        printf("Deleted = %d\n", removedItem);
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
}

void display(struct queue *q)
{
    int i;
    if (q->rear == -1)
    {
        printf("No elements in the queue");
    }
    else
    {
        // basically it is pointed at -1 so if we add 1 it becomes 0 i.e front = 0
        for (i = q->front + 1; i <= q->rear; i++)
        {
            printf("Elements at index %d is %d\n", i, q->arr[i]);
        }
    }
}

int main()
{
    struct queue *q;
    int choice;
    bool condition = false;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->max_size = 5;
    q->rear = -1;
    q->front = -1;
jump:
    printf("Enter 1. to insert the element in queue\n");
    printf("Enter 2. to delete the element in queue\n");
    printf("Enter 3. to display the element in queue\n");
    printf("Enter 4. to exit the queue\n");
    scanf("%d", &choice);
    // printf("inserted = %d\n", enqueue(q, 5));
    do
    {
        switch (choice)
        {
        case 1:
            enqueue(q, 5);
            enqueue(q, 9);
            enqueue(q, 8);
            enqueue(q, 0);
            enqueue(q, 2);
            goto jump;

        case 2:
            dequeue(q);
            goto jump;

        case 3:
            display(q);
            goto jump;

        case 4:
            printf("Exiting ...............\t\t\t\n");
            condition = true;
            break;

        default:
            printf("Please enter the correct value !\n");
            condition = true;
            break;
        }
    } while (!condition);

    return 0;
}