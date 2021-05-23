// Implementation of Linked List menu
// driven program for queue

#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
       struct LinkedList *next;
       int data;
}node;

int enqueue(node **, node **, int);
int dequeue(node **, node **);
int display(node **,node **);

void main()
{
       node *front=NULL, *rear=NULL;
       int n, c;
       do
       {
              printf("\nMENU : ");
              printf("\n1. Enqueue ");
              printf("\n2. Dequeue ");
              printf("\n3. Display ");
              printf("\n0. Exit ");
              printf("\nEnter your choice: ");
              scanf("%d",&c);

              switch(c)
              {
              case 1:
                     printf("\nEnter the number: ");
                     scanf("%d",&n);
                     enqueue(&front,&rear,n);
                     break;
              case 2:
                     printf("%d was dequeued! ",dequeue(&front,&rear));
                     break;
              case 3:
                     display(&front,&rear);
                     break;
              case 0:
                     break;
              default:
                     printf("\nINVALID CHOICE!\n");
              }
       }while(c!=0);
}

int enqueue(node **front, node **rear, int n)
{
       node *newnode = (node *)malloc(sizeof(node));
       if(newnode==NULL)
       {
              printf("\nOVERFLOW! ");
              return -1;
       }

       newnode->data = n;
       newnode->next=NULL;
       if(*front==NULL)
       {
              *front=*rear=newnode;
              return 0;
       }
       (*rear)->next=newnode;;
       *rear=newnode;
       return 0;
}

int dequeue(node **front, node **rear)
{
       node *temp=*front;
       int n;
       if(front==NULL)
       {
              printf("\nUNDERFLOW! ");
              return -1;
       }
       if(*front==*rear)
       {
              n=(*front)->data;
              *front=*rear=NULL;
              free(temp);
              return n;
       }
       n=(*front)->data;
       *front=(temp)->next;
       free(temp);
       return n;
}

int display(node **front,node **rear)
{
       node *temp=*front;
       if(temp==NULL)
       {
              printf("\nEMPTY QUEUE! ");
              return -1;
       }
       while(temp!=NULL)
       {
              printf("%d  ",temp->data);
              temp=temp->next;
       }
       return 0;
}
