#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 10

struct stack
{
       char a[max];
       int top;
};

int push(struct stack *s, char c);
char pop(struct stack *s);
int precedence(char c1,char c2);
int isEmpty(struct stack *s);

void main()
{
       struct stack s;
       char c[max],op[max],sym,temp1,temp2;
       int i,j=0,k;

       s.top=-1;

       printf("\nEnter the infix expression:  ");
       gets(c);

       for(i=0;i<strlen(c);i++)
       {
              if(isalnum(c[i]))
              {
                     op[j++]=c[i];
              }
              else
              {
                     while(isEmpty(&s)&&precedence(s.a[s.top],c[i]))
                     {
                            sym=pop(&s);
                            temp1=op[0];
                            op[0]=sym;
                            for(k=1;k<j+1;k++)
                            {
                                   temp2=op[k];
                                   op[k]=temp1;
                                   temp1=temp2;
                            }
                     }
                     push(&s,c[i]);
              }


       }

       while(isEmpty(&s))
       {
              sym=pop(&s);
              temp1=op[0];
              op[0]=sym;
              for(k=1;k<j+2;k++)
              {
                     temp2=op[k];
                     op[k]=temp1;
                     temp1=temp2;
              }
       }
       op[k]='\0';
       printf("\n%s",op);
}


int isEmpty(struct stack *s)
{
       if(s->top==-1)
              return 0;
       return 1;
}



int precedence(char c1,char c2)
{
       if(c1=='%'||c1=='$')
       {
              if(c2=='%'||c2=='$'||c2=='+'||c2=='-'||c2=='*'||c2=='/')
                     return 1;
              return 0;
       }
       if(c1=='*'||c1=='/')
       {
              if(c2=='+'||c2=='-'||c2=='*'||c2=='/')
                     return 1;
              return 0;
       }
       if(c1=='+'||c1=='-')
       {
              if(c2=='+'||c2=='-')
                     return 1;
              return 0;
       }
       return 0;
}

int push(struct stack *s, char c)
{
       if(s->top>=max-1)
       {
              return 0;
       }
       else
       {
              s->top=s->top+1;
              s->a[s->top]=c;
              return 1;
       }
}

char pop(struct stack *s)
{
      if(isEmpty(s))
      {
             return s->a[s->top--];
      }
      return '\0';
}
