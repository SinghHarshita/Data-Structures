// Menu driven program to perform different 
// operations on Singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

int insertBegin(struct LinkedList **,int);
int display(struct LinkedList *);
int insertEnd(struct LinkedList **,int);
int insertElement(struct LinkedList **,int,int);
int deleteBegin(struct LinkedList **);
int deleteEnd(struct LinkedList **);
int deleteElement(struct LinkedList **,int);

void main()
{
    struct LinkedList *start=NULL, *newnode;
    int n, choice, element;

    do
    {
        printf("\nMenu:-\n");
        printf("\n1. Insert at Beginning ");
        printf("\n2. Insert at End");
        printf("\n3. Insert after an element ");
        printf("\n4. Delete at Beginning ");
        printf("\n5. Delete at End ");
        printf("\n6. Delete a particular element ");
        printf("\n7. Display List ");
        printf("\n0. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter the number to be added: ");
                scanf("%d",&n);
                insertBegin(&start,n);
                break;

            case 2:printf("\nEnter the number to be added: ");
                scanf("%d",&n);
                insertEnd(&start,n);
                break;

            case 3:printf("\nEnter the number to be added: ");
                scanf("%d",&n);
                printf("\nEnter the element after which the number is to be added: ");
                scanf("%d",&element);
                insertElement(&start,n,element);
                break;

            case 4: n=deleteBegin(&start);
                if(n!=-1)
                    printf("%d was deleted",n);
                break;

            case 5: n=deleteEnd(&start);
                if(n!=-1)
                {
                    printf("\n%d was deleted! ",n);
                }
                break;

            case 6: printf("\nEnter the number to be deleted: ");
                scanf("%d",&n);
                element=deleteElement(&start,n);
                if(element!=-1)
                {
                    printf("\n%d was deleted! ",element);
                }
                break;

            case 7: display(start);
                break;

            case 0: printf("\nExiting...\n\n");
                break;

            default: printf("\nInvalid Choice!\n\n");
        }
    }
    while(choice!=0);
}

int insertBegin(struct LinkedList **start, int n)
{
    struct LinkedList *newnode, *avail;
    avail = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    if(avail==NULL)
    {
        printf("\nOverflow Occurred! \n\n");
        return -1;
    }

    newnode=avail;
    newnode->data=n;

    if(*start==NULL)
    {
        *start=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=*start;
        *start=newnode;
    }
    return 0;
}

int display(struct LinkedList *start)
{
    struct LinkedList *ptr = start;

    if(ptr==NULL)
    {
        printf("\nList is empty! ");
        return -1;
    }

    while(ptr!=NULL)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
    return 1;
}

int insertEnd(struct LinkedList **start,int n)
{
    struct LinkedList *ptr=*start, *newnode, *avail;
     avail = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    if(avail==NULL)
    {
        printf("\nOverflow Occurred! \n\n");
        return -1;
    }

    while(ptr->next!=NULL)
        ptr=ptr->next;

    newnode=avail;
    ptr->next=newnode;
    newnode->next=NULL;
    newnode->data=n;

    return 0;
}

int insertElement(struct LinkedList **start ,int n, int element)
{
    struct LinkedList *ptr=*start, *temp, *newnode, *avail;
    int x;
    avail = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    if(avail==NULL)
    {
        printf("\nOverflow Occurred! \n\n");
        return -1;
    }

    while(ptr->data!=element&&ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    x=(ptr->data);

    if(x!=element)
    {
        printf("\n%d data not found! ",element);
        return -1;
    }

    newnode=avail;
    newnode->data=n;

    temp=ptr->next;
    ptr->next=newnode;
    newnode->next=temp;
    return 0;
}

int deleteBegin(struct LinkedList **start)
{
    int value;
    struct LinkedList *ptr;
    if(*start==NULL)
    {
        printf("\nUnderflow Condition ! ");
        return -1;
    }
    ptr = *start;
    value=(*start)->data;
    if((*start)->next!=NULL)
            *start=(*start)->next;
    else
        *start=NULL;
    free(ptr);
    return value;
}


int deleteEnd(struct LinkedList **start)
{
    int value;
    struct LinkedList *ptr=*start,*temp;
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
        temp=ptr;
        ptr=ptr->next;
    }
    value=ptr->data;
    temp->next=NULL;
    return value;
}


int deleteElement(struct LinkedList **start,int n)
{
    struct LinkedList *ptr=*start, *temp;
    int value;
    if(*start==NULL)
    {
        printf("\nUnderflow Condition ! ");
        return -1;
    }

    if(ptr->data==n)
    {
         value=(*start)->data;
        if(ptr->next==NULL)
        {
            *start=NULL;
            return value;
        }
        else
        {
            (*start)=(*start)->next;
            return value;
        }
    }

    while(ptr->data!=n)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    value=ptr->data;

    if(ptr->next==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        ptr=ptr->next;
        temp->next=ptr;
    }
    return value;
}
