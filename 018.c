#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}queue;

int enqueue(queue **top, int n);
int dequeue(queue **top);
int display(queue **top);

void main()
{
    queue *top=NULL;
    int n,c;

    do
    {
        printf("\nMENU:- ");
        printf("\n1. Enqueue ");
        printf("\n2. Dequeue ");
        printf("\n3. Display ");
        printf("\n0. Exit ");
        printf("\nEnter the choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the number: ");
                    scanf("%d",&n);
                    enqueue(&top,n);
                    break;
            case 2: n = dequeue(&top);
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

int enqueue(queue **top, int n)
{
    queue *newnode = (queue *)malloc(sizeof(queue)),*ptr=*top;
    if(newnode==NULL)
    {
        printf("\nOverflow! ");
        return -1;
    }
    newnode->data=n;
    newnode->next=NULL;
    if(*top==NULL)
    {
         *top=newnode;
         return 0;
    }
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=newnode;
    return 0;
}

int dequeue(queue **top)
{
    queue *ptr=*top;
    int n;
    if(ptr==NULL)
    {
        printf("\nUnderflow! ");
        return -1;
    }
    *top = (*top)->next;
    n=ptr->data;
    free(ptr);
    return n;
}

int display(queue **top)
{
    queue *ptr = *top;
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
