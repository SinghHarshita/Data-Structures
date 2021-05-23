// Menu Driven Program to implement different operations on Circular Queue

#include<stdio.h>
#define max 10

struct queue
{
       int a[max], front, rear;
};

int enqueue(struct queue *q, int n);
int dequeue(struct queue *q);
int display(struct queue *q);
int isFull(struct queue *q);
int isEmpty(struct queue *q);

void main()
{
       int n, i;
       struct queue q;

       q.front=-1;
       q.rear=-1;

       do
       {
              printf("\nMENU: ");
              printf("\n1. Enqueue ");
              printf("\n2. Dequeue ");
              printf("\n3. Display ");
              printf("\n0. Exit ");
              printf("\nEnter your choice: ");
              scanf("%d",&i);

              switch(i)
              {
                     case 1:
                            printf("\nEnter the number: ");
                            scanf("%d",&n);
                            enqueue(&q,n);
                            break;
                     case 2:
                            printf("\n%d was dequeued.",dequeue(&q));
                            break;
                     case 3:
                            display(&q);
                            break;
                     case 0:
                            printf("\nExiting................\n\n");
                            break;
                     default: printf("\nInvalid Choice!!!\n\n\n");
              }
       }while(i!=0);
}


int isFull(struct queue *q)
{
       if(q->rear==q->front-1)
       {
              return 1;
       }
       if(q->front==0&&q->rear==max-1)
              return 1;
       return 0;
}


int isEmpty(struct queue *q)
{
       if(q->front==-1&&q->rear==-1)
              return 1;
       return 0;
}

int enqueue(struct queue *q, int n)
{
       int i=0;
       if(isFull(q))
       {
              printf("\nQueue Full!");
              return -1;
       }
       if(q->front==-1&&q->rear==-1)
       {
              q->front=0;
              q->rear=0;
       }
       else if(q->front!=0&&q->rear==max-1)
       {
              q->rear=0;
              i=1;
       }
       else
       {
              q->rear=q->rear+1;
       }
       q->a[q->rear]=n;
       return 1;
}


int dequeue(struct queue *q)
{
       int r;
       if(isEmpty(q))
       {
              printf("\nQueue Empty");
              return 0;
       }
       if(q->rear<q->front&&q->front==max-1)
       {
              r=q->a[q->front];
              q->front=0;
              return r;
       }
       else if(q->front==q->rear)
       {
              r=q->a[q->front];
              q->front=-1;
              q->rear=-1;
              return r;
       }
       else
       {
              return q->a[q->front++];
       }
}

int display(struct queue *q)
{
       int i;

       if(isEmpty(q))
       {
              printf("\nQUEUE IS EMPTY!!!!");
       }

       if(q->front<q->rear)
       {
              for(i=q->front;i<=q->rear;i++)
              {
                     printf(" %d ",q->a[i]);
              }
              return 1;
       }

       else
       {
              for(i=q->front;i<max;i++)
              {
                     printf(" %d ",q->a[i]);
              }
              for(i=0;i<=q->rear;i++)
              {
                     printf(" %d ",q->a[i]);
              }
       }
}
