#include<stdio.h>
#include<stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

int insertEnd(struct LinkedList **,int);
int display(struct LinkedList *);
int deleteBegin(struct LinkedList **);
int countOfNodes(struct LinkedList **);
void reverseList(struct LinkedList **);
void concatList(struct LinkedList **, struct LinkedList **);
void splitList(struct LinkedList **, struct LinkedList **, int pos);

void main()
{
    struct LinkedList *start1=NULL, *start2=NULL;
    int n, c;
    do
    {
        printf("\nMenu:- ");
        printf("\n1. Insert element ");
        printf("\n2. Delete element ");
        printf("\n3. Count number of nodes ");
        printf("\n4. Concatenate List ");
        printf("\n5. Split List ");
        printf("\n0. Exit ");
        printf("\nEnter your choice:- ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the number to be inserted: ");
                    scanf("%d",&n);
                    insertEnd(&start1,n);
                    break;
            case 2: printf("\n%d was deleted! ",deleteBegin(&start1));
                    break;
            case 3: printf("\nCount = %d",countOfNodes(&start1));
                    break;
            case 4: concatList(&start1,&start2);
                    break;
            case 5: printf("\nEnter the position: ");
                    scanf("%d",&n);
                    splitList(&start1,&start2,n);
                    break;
            case 0: printf("\nExiting..........\n\n\n");
                    break;
            default: printf("\nINVALID CHOICE! ");
        }
    }while(c!=0);
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
    newnode=avail;
    newnode->next=NULL;
    newnode->data=n;

    if(*start==NULL)
    {
        *start = newnode;
        return 0;
    }

    while(ptr->next!=NULL)
        ptr=ptr->next;


    ptr->next=newnode;


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

int countOfNodes(struct LinkedList **start)
{
    int count = 0;
    struct LinkedList *ptr = *start;

    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }

    return count;
}


void concatList(struct LinkedList **start1, struct LinkedList **start2)
{
    struct LinkedList *ptr=*start1;
    if(*start1==NULL&&*start2==NULL)
    {
        printf("\nEmpty lists! ");
        return;
    }
    if(*start1==NULL&&*start2!=NULL)
    {
        ptr=*start1=*start2;
        printf("\nConcatenated List: \n");
        display(ptr);
        return;
    }
    if(*start1!=NULL&&*start2==NULL)
    {
        printf("\nConcatenated List: ");
        display(ptr);
        return;
    }
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=*start2;
    ptr=*start1;
    printf("\nConcatenated List: ");
    display(ptr);
}

void splitList(struct LinkedList **start1, struct LinkedList **start2, int pos)
{
    struct LinkedList *ptr = *start1;
    int n=0;
    if(ptr==NULL)
    {
        printf("\nList is empty! ");
        return;
    }
    while(ptr->next!=NULL&&n!=pos)
    {
        ptr=ptr->next;
        n++;
    }
    if(ptr->next==NULL&&n!=pos)
    {
        printf("\nPosition Not Found! ");
        return;
    }
    *start2 = ptr->next;
    ptr->next = NULL;
    printf("\nList 1: ");
    ptr=*start1;
    display(ptr);
    printf("\nList 2: ");
    ptr=*start2;
    display(ptr);
}
