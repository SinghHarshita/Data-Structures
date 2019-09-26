#include<stdio.h>
#include<string.h>
#define max 10

struct stack
{
    int a[max];
    int top;
};

struct Stack
{
    char a[max];
    int top;
};

int push1(struct stack *s, int n);
int push2(struct Stack *s, char n);
char pop(struct Stack *s);
int isFull(struct stack *s);
int Full(struct Stack *s);
int Empty(struct Stack *s);
void display(struct stack *s);

void main()
{
    struct stack s;
    struct Stack s1;
    int n, temp, d, i,j;
    char c[max];
    s.top=-1;
    s1.top=-1;
    printf("1. Find Binary Equivalent");
    printf("\n2. Check Balance Parentheses");
    printf("\nEnter choice: ");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
            printf("\nEnter the number in decimal: ");
            scanf("%d",&n);
            temp=n;
            while(temp!=0)
            {
                d=temp%2;
                push1(&s,d);
                temp/=2;
            }
            printf("Binary equivalent is: \n");
            display(&s);
            break;

        case 2:
            printf("\nEnter expression: ");
            scanf("%s",c);
            for(j=0;j<strlen(c);j++)
            {
                if(c[j]=='(')
                    push2(&s1,c[j]);
                else if(c[j]==')')
                    pop(&s1);
            }
            if(s1.top==-1)
                printf("\nBalanced Parentheses");
            else
                printf("\nUnbalanced Parentheses");
            break;
        default: printf("\nInvalid Choice!");
    }
}


int push1(struct stack *s, int n)
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

int push2(struct Stack *s, char n)
{
    if(Full(s))
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

int Full(struct Stack *s)
{
    if(s->top==max-1)
        return 1;
    return 0;
}

int Empty(struct Stack  *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}

char pop(struct Stack *s)
{
    if(Empty(s))
    {
        printf("\nStack Empty!");
        return '\0';
    }
    return (s->a[s->top--]);
}

void display(struct stack *s)
{
    int i;
    for(i=s->top;i>=0;i--)
        printf("%d",s->a[i]);
}
