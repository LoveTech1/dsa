#include <stdio.h>
#include <stdlib.h>

// defining the structure
struct stack
{
    int top;      // 4;
    int *arr;     // 4
    int max_size; //
};

// to check if the stack is empty
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is full\n");
        return 0;
    }
}

// to check if the stack is full
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
int push(struct stack *s, int arr[], int numOfElements)
{
    int i = 0;
    if (isFull(s))
    {
        printf("Cannot push it into stack , overflow!\n");
    }

    else
    {
        if (numOfElements <= s->max_size)
        {
            for (i = 0; i < numOfElements; i++)
            {
                s->top += 1;
                s->arr[s->top] = arr[i];
                printf("Pushed element to stack: %d\n", arr[i]);
                if ((sizeof(*arr) / sizeof(int)) == numOfElements)
                {
                    break;
                }
            }
        }
        else
        {
            printf("NumOfElements to push can't exceed the max size!\n");
            return -1;
        }
    }
}

void popping(struct stack *s, int numOfElement)
{
    int i, data;
    int returningArr[numOfElement];
    if (!isEmpty(s))
    {
        for (i = 0; i < numOfElement; i++)
        {
            // example = arr[3] == arr[3]
            data = s->arr[s->top];
            returningArr[i] = data;
            s->top--;
        }
    }
    else
    {
        printf("Stack is empty\n");
    }
    for (i = 0; i < numOfElement; i++)
    {
        printf("popped: %d\n", returningArr[i]);
    }
}
void isGreaterThanPopElements(struct stack *s, int noOfElements, int popNumbers)
{
    if (noOfElements >= popNumbers)
    {
        popping(s, popNumbers);
    }
    else
    {
        printf("Your pop element can't exceed the noOfElements in the array!\n");
    }
}

// Peak function
int peak(struct stack *s, int pos)
{
    // pos will point the top most part of the stack
    if (s->top - pos + 1 < 0)
    {
        printf("Please provide valid position \n");
        return -1;
    }
    else
    {
        return s->arr[s->top - pos + 1];
    }
}
void green()
{
    printf("\033[0;32m");
}
void reset()
{
    printf("\033[0m");
}

int main()
{
    struct stack *s;
    int n, choice, noOfElements, pos;
    int popNumbers;
    int ch, k;
    int ar[] = {2, 3, 4, 5, 9, 10};
    // dynamically defining the maxsize of the structure pointer
    s = (struct stack *)malloc(sizeof(struct stack));

    // defining the max_size
    printf("Enter the max_size of an array: ");
    scanf("%d", &n);
    // printf("Enter no. of elements you want to push from an array? ");
    // scanf("%d", &noOfElements);
    s->max_size = n;
    // defining the top most element
    s->top = -1;
    s->arr = (int *)calloc(sizeof(s->max_size - 1), sizeof(int));

    printf("Enter 1 to check if stack is empty? \n");
    printf("Enter 2 to check if the stack is full? \n");
    printf("Enter 3 to push the elements? \n");
    printf("Enter 4 to pop the elements? \n");
    printf("Enter 5 to take a peak at stack\n");
    printf("Enter your choice? \n");
    scanf("%d", &choice);
    // creating switch list
    switch (choice)
    {
    case 1:
        isEmpty(s);
        break;
    case 2:
        isFull(s);
        break;

    case 3:
        printf("Enter no. of elements you want to push from an array? ");
        scanf("%d", &noOfElements);
        push(s, ar, noOfElements);
        break;

    case 4:
        // push(s, ar, noOfElements);
        isEmpty(s);
        printf("Enter no. of elements you want to push from an array? \n");
        scanf("%d", &noOfElements);
        // }
        push(s, ar, noOfElements);
        if (noOfElements <= s->max_size)
        {
            printf("Enter no. of elements you want to pop from an array? \n");
            scanf("%d", &popNumbers);
        }
        else
        {
            printf("You can't pop unless you have some element in the stack\n");
            break;
        }
        isGreaterThanPopElements(s, noOfElements, popNumbers);
        break;

    case 5:
        isEmpty(s);
        green();
        printf("You need to first push the elements to peek at the stack!\n");
        reset();
        printf("Enter no. of elements you want to push from an array? \n");
        scanf("%d", &noOfElements);
        push(s, ar, noOfElements);
        // printf("top = %d\n", s->top);
        for (k = 1; k <= s->top + 1; k++)
        {
            printf("Element at index: %d and element :  %d\n", k, peak(s, k));
        };
        break;

    default:
        return 0;
    }

    return 0;
}