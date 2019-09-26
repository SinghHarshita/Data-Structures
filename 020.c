#include<stdio.h>
#define N 100

void display(int a[],int n);
int search(int a[],int n);

void insert(int a[], int n)
{
    int key,val, f=0, i;

    printf("\nEnter the element to be inserted: ");
    scanf("%d",&val);

    key = (val%n)-1;
    if(a[key]==-1)
    {
        a[key] = val;
        f=1;
        return;
    }
    if(key<9)
    {
        for(i=key+1;i<n;i++)
        {
            if(a[i]==-1)
            {
                a[i] = val;
                f=1;
                return;
            }
        }
    }
    for(i=0;i<key;i++)
    {
        if(a[i]==-1)
        {
            a[i] = val;
            return;
        }
    }
    if(f==0)
    {
        printf("ARRAY IS FULL! ");
    }
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("\n%d",a[i]);
}

int search(int a[], int n)
{
    int i, val, flag=0;

    printf("\nEnter the value to be searched: ");
    scanf("%d",&val);

    for(i=0;i<n;i++)
    {
        if(a[i]==val)
            return i;
    }
    return -1;
}

void main()
{
    int n,a[N],i,choice;

    printf("Enter the number of elements:- ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        a[i]=-1;

    do
    {
        printf("\nMenu:- ");
        printf("\n1. Insert ");
        printf("\n2. Search ");
        printf("\n3. Display ");
        printf("\n0. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insert(a,n);
                    break;
            case 2: i=search(a,n);
                    if(i!=-1)
                        printf("\nElement found at %d",i+1);
                    else
                        printf("\nElement not found! ");
                    break;
            case 3: display(a,n);
                    break;
            case 4: printf("\nExiting.........");
                    break;
            default: printf("\nInvalid Choice!!! ");
        }
    }while(choice!=0);
}
