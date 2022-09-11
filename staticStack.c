#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack
{
    int top;
    int arr[5];
    int max_size;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        printf("The stack is empty\n");
        return -1;
    }
    return 0;
}
int isFull(struct stack *s)
{
    if (s->top == s->max_size - 1)
    {
        printf("The stack is full\n");
        return 1;
    }
    else
    {
        printf("The stack is not full\n");
        return 0;
    }
}

void push(struct stack *s, int item)
{
    if (isFull(s))
    {
        printf("Cannot push into stack overflow!\n");
    }
    else
    {
        if (s->top < s->max_size - 1)
        {
            s->top += 1;
            s->arr[s->top] = item;
            printf("Pushed element : %d  \n", item);
        }
        else
        {
            printf("Max size exceeded!\n");
        }
    }
}
void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Cannot pop from the stack . It is empty !\n");
    }
    else
    {
        int item = s->arr[s->top];
        printf("Popped : %d \n", item);
        s->top -= 1;
    }
}
void display(struct stack *s, int showItemAtIndex)
{
    int i;

    for (i = s->top; i >= 0; i--)
    {

        printf("%d\t\n", s->arr[i]);
    }
    if (s->top == -1)
    {
        printf("Stack is empty.");
    }
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    int choice;
    s->max_size = 5;
    s->top = -1;
    bool condition = false;
jump:
    printf("Enter 1. to push to the stack \n");
    printf("Enter 2. to pop from the stack\n");
    printf("Enter 3. to display the items from the stack\n");
    scanf("%d", &choice);

    do
    {

        switch (choice)
        {
        case 1:
            push(s, 3);
            push(s, 4);
            push(s, 5);
            goto jump;

        case 2:
            pop(s);
            pop(s);
            goto jump;

        case 3:
            display(s, 2);
            goto jump;
            break;

        default:
            printf("Please enter correct value !\n");
            condition = true;
            break;
        }
    } while (!condition); // if the condition will be true

    return 0;
}