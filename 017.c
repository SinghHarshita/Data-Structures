#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}stack;

int push(stack **top, int n);
int pop(stack **top);
int display(stack **top);

void main()
{
    stack *top=NULL;
    int n,c;

    do
    {
        printf("\nMENU:- ");
        printf("\n1. Push ");
        printf("\n2. Pop ");
        printf("\n3. Display ");
        printf("\n0. Exit ");
        printf("\nEnter the choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the number: ");
                    scanf("%d",&n);
                    push(&top,n);
                    break;
            case 2: n = pop(&top);
                    printf("\n%d was popped!",n);
                    break;
            case 3: display(&top);
                    break;
            case 0: printf("\nExiting..............\n\n");
                    break;
            default: printf("\nInvalid Choice!! ");
        }
    }while(c!=0);
}

int push(stack **top, int n)
{
    stack *newnode = (stack *)malloc(sizeof(stack));

    if(newnode==NULL)
    {
        printf("\nOVERFLOW! ");
        return -1;
    }
    newnode->data = n;
    newnode->next = NULL;
    if(*top!=NULL)
        newnode->next = *top;
    *top = newnode;
    return 0;
}

int pop(stack **top)
{
    int n;
    stack *ptr;
    ptr=*top;
    if(ptr==NULL)
    {
        printf("\nUNDERFLOW! ");
        return -1;
    }
    n = ptr->data;
    *top = (*top)->next;
    free(ptr);
    return n;
}

int display(stack **top)
{
    stack *ptr = *top;
    if(ptr==NULL)
    {
        printf("\nNo nodes! ");
        return -1;
    }
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
