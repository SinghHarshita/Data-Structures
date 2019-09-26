#include<stdio.h>
#define max 10

struct stack
{
    int a[max];
    int top;
};

int push(struct stack *s, int n);
int pop(struct stack *s);
int peek(struct stack *s);
int isFull(struct stack *s);
int isEmpty(struct stack *s);
void display(struct stack *s);

void main()
{
    struct stack s; int i,r,b,n;
    s.top=-1;
    do
    {
        printf("\nMenu: \n\n");
        printf("\n1. Push ");
        printf("\n2. Pop ");
        printf("\n3. Display ");
        printf("\n4. Peek ");
        printf("\n0. Exit ");
        printf("\nEnter choice: ");
        scanf("%d",&i);

        switch(i)
        {
            case 0:
                printf("\nExiting..............\n\n");
                break;
            case 1:
                printf("\n\nEnter the number to be pushed: ");
                scanf("%d",&n);
                push(&s,n);
                break;
            case 2:
                printf("\n%d was popped from the stack.",pop(&s));
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("\nThe topmost element is %d",peek(&s));
                break;
            default:
                printf("\n\nInvalid Choice!!\n\n\n");
        }
    }while(i!=0);
}

int push(struct stack *s, int n)
{
    if(isFull(s))
    {
        printf("\nStack is full. Can't push the number.");
        return 0;
    }
    s->top+=1;
    s->a[s->top]=n;
    return s->top;
}

int isFull(struct stack *s)
{
    if(s->top==max-1)
        return 1;
    return 0;
}

int isEmpty(struct stack  *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}

int pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("\nStack Empty!");
        return 0;
    }
    return (s->a[s->top--]);
}

int peek(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Empty");
        return 0;
    }
    return s->a[s->top];
}

void display(struct stack *s)
{
    int i;
    for(i=s->top;i>=0;i--)
        printf("\n%d",s->a[i]);
}
