#include<stdio.h>
#define max 10

struct stack
{
    int a[max];
    int top1, top2;
};

int push1(struct stack *s, int n);
int pop1(struct stack *s);
int isFull(struct stack *s);
int isEmpty(struct stack *s);
void display1(struct stack *s);
int push2(struct stack *s, int n);
int pop2(struct stack *s);
void display2(struct stack *s);

void main()
{
    struct stack s;
    int i,n,j;
    s.top1=-1;
    s.top2=max;
    do
    {
        printf("\nMenu: \n\n");
        printf("\n1. Push in first stack  ");
        printf("\n2. Pop from first stack");
        printf("\n3. Display first stack");
        printf("\n4. Push in second stack  ");
        printf("\n5. Pop from second stack");
        printf("\n6. Display second stack");
        printf("\n7. Display the whole array");
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
                push1(&s,n);
                break;
            case 2:
                printf("\n%d was popped from the stack.",pop1(&s));
                break;
            case 3:
                display1(&s);
                break;
            case 4:
                printf("\n\nEnter the number to be pushed: ");
                scanf("%d",&n);
                push2(&s,n);
                break;
            case 5:
                printf("\n%d was popped from the stack.",pop2(&s));
                break;
            case 6:
                display2(&s);
                break;
            case 7:
                printf("\n");
                for(j=0;j<max;j++)
                    printf("%d ",s.a[j]);
                break;
            default:
                printf("\n\nInvalid Choice!!\n\n\n");
        }
    }while(i!=0);
}

int push1(struct stack *s, int n)
{
    if(isFull(s))
    {
        printf("\nStack is full. Can't push the number.");
        return 0;
    }
    s->top1+=1;
    s->a[s->top1]=n;
    return s->top1;
}

int isFull(struct stack *s)
{
    if(s->top1==s->top2-1||s->top2==s->top1+1)
        return 1;
    return 0;
}

int isEmpty(struct stack  *s)
{
    if(s->top1==-1&&s->top2==max)
        return 1;
    return 0;
}

int pop1(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("\nStack Empty!");
        return 0;
    }
    return (s->a[s->top1--]);
}

void display1(struct stack *s)
{
    int i;
    for(i=s->top1;i>=0;i--)
        printf("\n%d",s->a[i]);
}

int push2(struct stack *s, int n)
{
    if(isFull(s))
    {
        printf("\nStack is full. Can't push the number.");
        return 0;
    }
    s->top2-=1;
    s->a[s->top2]=n;
    return s->top2;
}

int pop2(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("\nStack Empty!");
        return 0;
    }
    return (s->a[s->top2++]);
}

void display2(struct stack *s)
{
    int i;
    for(i=s->top2;i<max;i++)
        printf("\n%d",s->a[i]);
}
