// Menu driven program to perform different
// operations on Doubly Linked List.

#include<stdio.h>
#include<stdlib.h>

typedef struct DoublyLinkedList
{
    struct DoublyLinkedList *prev;
    int data;
    struct DoublyLinkedList *next;
}dll;

int insertBegin(dll **, int);
int insertEnd(dll **, int);
int deleteBegin(dll **);
int deleteEnd(dll **);
void displayBegin(dll **);

void main()
{
    dll *start=NULL;
    int c,val,num;

    do
    {
        printf("\nMENU: ");
        printf("\n1. Insert Begin ");
        printf("\n2. Insert End ");
        printf("\n3. Delete Begin ");
        printf("\n4. Delete After ");
        printf("\n5. Display From Start ");
        printf("\n0.Exit ");
        printf("\n\nEnter Choice: ");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("\nEnter the number to be inserted: ");
            scanf("%d",&val);
            if(start==NULL)
            {
                insertBegin(&start,val);
            }
            else
                insertBegin(&start,val);
            break;
        case 2:
            printf("\nEnter the number to be inserted: ");
            scanf("%d",&val);
            insertEnd(&start,val);
            break;
        case 3:
            deleteBegin(&start);
            break;
        case 4:
            deleteEnd(&start);
            break;
        case 5:
            displayBegin(&start);
            break;
        case 0:
            printf("\n\nExiting............\n\n\n");
            break;
        default:
            printf("\n\nINVALID CHOICE!\n\n");
        }

    }while(c!=0);
}


int insertBegin(dll **start, int val)
{
    dll *newnode=(dll *)malloc(sizeof(dll));

    if(newnode==NULL)
    {
        printf("\n\nOverflow!\n\n");
        return -1;
    }
    newnode->data=val;
    newnode->next=newnode->prev=NULL;
    if(*start==NULL)
    {
        *start=newnode;
        return 0;
    }
    newnode->next=*start;
    (*start)->prev=newnode;
    *start=newnode;
    return 0;
}


int insertEnd(dll **start, int val)
{
    dll *newnode=(dll *)malloc(sizeof(dll));
    dll *temp=*start;

    if(newnode==NULL)
    {
        printf("\n\nOverflow!\n\n");
        return -1;
    }
    newnode->data=val;
    newnode->next=newnode->prev=NULL;
    if(*start==NULL)
    {
        *start=newnode;
        return 0;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    newnode->prev=temp;
    temp->next=newnode;

    return 1;
}

int deleteBegin(dll **start)
{
     int value;
     dll *ptr=*start;
    if(*start==NULL)
    {
        printf("\nUnderflow Condition ! ");
        return -1;
    }

    value=(*start)->data;
    if((*start)->next!=NULL)
    {
        *start=(*start)->next;
        (*start)->prev=NULL;
    }

    else
        *start=NULL;
    free(ptr);
    return value;
}

int deleteEnd(dll **start)
{
   int value;
   dll *ptr=*start,*temp;
    if(*start==NULL)
    {
        printf("\nUnderflow Condition ! ");
        return -1;
    }
    if((*start)->next==NULL)
    {
        value = (*start)->data;
        *start=NULL;
        return value;
    }

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    value=ptr->data;
    (ptr->prev)->next=NULL;
    free(ptr);
    return value;
}

void displayBegin(dll **start)
{
    dll *ptr = *start;

    if(ptr==NULL)
    {
        printf("\nList is empty! ");
        return;
    }

    while(ptr!=NULL)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
    return;
}
