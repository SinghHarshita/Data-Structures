// Implementation of different operations
// on singly linked list – copy, concatenate,
// split, reverse, count no. of nodes

#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
       struct LinkedList *next;
       int data;
}node;

int copy(node,node);
int reverse(node, node);
int countNumberOfNodes(node **);
int enqueue(node **, node **, int);
int pop(node**);
void display(node **);

void main()
{
       node *start1=NULL, *start2=NULL, *end=NULL;
       int n,c;

       do
       {
              printf("\nMENU: ");
              printf("\n1. Push ");
              printf("\n2. Pop ");
              printf("\n3. Display list 1");
              printf("\n4. Copy ");
              printf("\n5. Reverse ");
              printf("\n6. Count the number of nodes ");
              printf("\n7. Display list 2 ");
              printf("\n0. Exit");
              printf("\nEnter your choice: ");
              scanf("%d",&c);

              switch(c)
              {
                     case 1:
                     printf("\nEnter the number: ");
                     scanf("%d",&n);
                     enqueue(&start1,&end,n);
                     break;
              case 2:
                     printf("\n%d was popped!",pop(&start1));
                     break;
              case 3:
                     display(&start1);
                     break;
              case 4:
                     printf("\nCopying...........");
                     copy(&start1,&start2);
                     break;
              case 5:
                     printf("\nReversing.............");
                     reverse(&start1,&start2);
                     break;
              case 6:
                     printf("\nCounting the number of nodes..............");
                     countNumberOfNodes(&start1);
                     break;
              case 7:
                     display(&start2);
                     break;
              case 0:
                     break;
              default:
                     printf("\nInvalid choice!\n");
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
 int copy(node **start1, node **start2)
 {
       node *temp1=(*start1)->next, *temp2;
       if(*start1==NULL)
       {
              printf("\nEmpty listed can't be copied! ");
              return -1;
       }
       *start2=*start1;
       (*start2)->data=(*start1)->data;
       (*start2)->next=(*start1)->next;
       temp2=(*start2)->next;
       while(temp1!=NULL)
       {
              temp2->data=temp1->data;
              temp2->next=temp1->next;
              temp2=temp1->next;
              temp1=temp1->next;
       }
       printf("\n\nDISPLAYING THE COPIED LIST: \n");
       display(&start2);
       return 0;
 }

int countNumberOfNodes(node **start)
{
       int n=1;
       node *temp=*start;
       while(temp->next!=NULL)
              n++;
       printf("\n The number of nodes = %d.",n);
       return n;
}

int reverse(node **start1, node **start2)
{
       node *temp1=start1, *temp2;
       int *arr=(int *)(malloc(countNumberOfNodes(&start1)*sizeof(int)));
       int i=0;
       if(temp1==NULL)
       {
              printf("\nEmpty list can't be reversed! ");
              return -1;
       }
       while(temp1!=NULL)
       {
              arr[i]=temp1->data;
              i++;
       }
       temp1=*start1;
       i=0;
       while(temp1!=NULL)
       {
              temp1->data=arr[i];
              i++;
       }
       display(&start1);
       return 1;
}
