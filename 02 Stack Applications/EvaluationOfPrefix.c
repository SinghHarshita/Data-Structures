//evaluation of prefix expression

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 10

struct stack
{
       int a[max];
       int top;
};

int push(struct stack *s, int n);
int pop(struct stack *s);
int isOperator(char c);
int evaluation(char c, struct stack *s);

void main()
{
       char input[max];
       struct stack s;
       int i,eval;
       s.top=-1;
       printf("Enter the prefix expression: ");
       scanf("%s",input);
       i=strlen(input)-1;
       while(i>=0)
       {
              if(isalnum(input[i]))
              {
                     push(&s,(int)(input[i]-'0'));
              }
              else if(isOperator(input[i]))
              {
                     eval=evaluation(input[i],&s);
                     push(&s,eval);
              }
              i--;
       }
       printf("Evaluated expression= %d",pop(&s));
}

int push(struct stack *s,int n)
{
       if(s->top==max-1)
       {
              printf("\nStack Overflow");
              return 0;
       }
       s->top=s->top+1;
       s->a[s->top]=n;
       return 1;
}

int pop(struct stack *s)
{
       if(s->top==-1)
       {
              printf("\nUnderflow");
              return 0;
       }
       return (s->a[s->top--]);
}

int isOperator(char c)
{
       if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%')
              return 1;
       else
              return 0;
}

int evaluation(char c, struct stack *s)
{
       int op1, op2;
       if(c=='+')
       {
              op1=pop(s);
              op2=pop(s);
              return (op1+op2);
       }
       else if(c=='-')
       {
              op1=pop(s);
              op2=pop(s);
              return (op1-op2);
       }
       else if(c=='*')
       {
              op1=pop(s);
              op2=pop(s);;
              return (op1*op2);
       }
       else if(c=='/')
       {
              op1=pop(s);
              op2=pop(s);
              return (op1/op2);
       }
       else if(c=='%')
       {
              op1=pop(s);
              op2=pop(s);
              return (op1%op2);
       }
}
