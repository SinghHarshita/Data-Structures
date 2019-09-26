#include<stdio.h>
#define N 100

void bubbleSort(int array[], int n);
void selectionSort(int arr[],int n);
void insertionSort(int arr[], int n);


void main()
{
    int a[N],n,i,c;

    printf("\nEnter the number of elements: ");
    scanf("%d",&n);

    if(n>100)
    {
        printf("\nToo many numbers! ");
        return;
    }

    printf("\nEnter the numbers one by one- ");

    for(i=0;i<n;i++)
    {
        printf("\nEnter number %d: ",i+1);
        scanf("%d",&a[i]);
    }

    printf("\nMenu:- ");
    printf("\n1. Bubble sort ");
    printf("\n2. Selection sort ");
    printf("\n3. Insertion sort ");
    printf("\nEnter your choice: ");
    scanf("%d",&c);

    switch(c)
    {
        case 1: bubbleSort(a,n);
            break;
        case 2: selectionSort(a,n);
            break;
        case 3: insertionSort(a,n);
            break;
        default: printf("\nINVALID CHOICE! ");
    }
}

void bubbleSort(int array[],int n)
{
    int c,d,swap;

    for (c=0;c<n-1;c++)
    {
        for (d=0;d<n-c-1;d++)
        {
            if (array[d]>array[d+1])
            {
                swap=array[d];
                array[d]=array[d+1];
                array[d+1]=swap;
            }
        }
    }
    printf("\nSorted list in ascending order:\n");

    for (c = 0; c < n; c++)
        printf("%d\n", array[c]);
}


void selectionSort(int arr[],int n)
{
    int i, j, min_idx,swap;

    for (i=0;i<n-1;i++)
    {
        min_idx=i;
        for (j=i+1;j<n;j++)
          if (arr[j] < arr[min_idx])
            min_idx=j;

        swap=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=swap;
    }

    printf("\nSorted list in ascending order:\n");

    for (i=0;i<n;i++)
        printf("%d\n", arr[i]);
}


void insertionSort(int arr[],int n)
{
int i, key, j;
   for (i=1;i<n;i++)
   {
       key=arr[i];
       j=i-1;
       while(j>=0&&arr[j]>key)
       {
           arr[j+1]=arr[j];
           j=j-1;
       }
       arr[j+1]=key;
   }
   printf("\nSorted list in ascending order:\n");

    for (i=0;i<n;i++)
        printf("%d\n", arr[i]);
}
