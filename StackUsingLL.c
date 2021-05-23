// Implementation of Linked List menu
// driven program for stack

#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
       struct LinkedList *next;
       int data;
}node;

int push(node **,int);
int pop(node**);
void display(node **);

void main()
{
       node *top=NULL;
       int n,c;
       do
       {

              printf("\nMENU: ");
              printf("\n1. Push ");
              printf("\n2. Pop ");
              printf("\n3. Display ");
              printf("\n0. Exit");
              printf("\nEnter your choice: ");
              scanf("%d",&c);

              switch(c)
              {
              case 1:
                     printf("\nEnter the value to be pushed: ");
                     scanf("%d",&n);
                     push(&top,n);
                     break;
              case 2:
                     printf("\n%d was popped!",pop(&top));
                     break;
              case 3:
                     display(&top);
                     break;
              case 0:
                     break;
              default:
                     printf("\nInvalid choice!\n");
              }

       }while(c!=0);
}

int push(node **top, int n)
{
       node *newnode = (node *)malloc(sizeof(node));
       if(newnode == NULL)
       {
              printf("\nOverflow!");
              return -1;
       }
       newnode->data=n;
       newnode->next=NULL;
       if(*top==NULL)
       {
              *top=newnode;
              return 0;
       }
       newnode->next=(*top);
       *top=newnode;
       return 1;
}

int pop(node **top)
{
       int n;
       node *temp=*top;
       if(*top==NULL)
       {
              printf("\nUnderflow! ");
              return -1;
       }
       if((*top)->next==NULL)
       {
              n=(*top)->data;
              *top=NULL;
              free(temp);
              return n;
       }
       n=(*top)->data;
       *top=(*top)->next;
       free(temp);
       return n;
}

void display(node **start)
{
       node *top=*start;
       if(top==NULL)
       {
              printf("\nThe stack is empty! ");
              return;
       }
       while((top)!=NULL)
       {
              printf("%d\t",(top)->data);
              top=(top)->next;
       }
}
