// Menu Driven Program for Quick Sort,
// Merge sort and Heap Sort.

#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int m,int r);
void mergeSort(int arr[],int l,int r);
void printArray(int A[], int size);
int partition (int arr[],int low,int high);
void quickSort(int arr[],int low,int high);
void heapify(int arr[],int n,int i);
void heapSort(int arr[], int n);

void main()
{
    int *a, n, i, c;

    printf("\nEnter the number of elements: ");
    scanf("%d",&n);

    a=(int *)calloc(n,sizeof(int));

    for(i=0;i<n;i++)
    {
        printf("\nEnter number %d: ",i+1);
        scanf("%d",&a[i]);
    }
     printf("\nMENU: ");
     printf("\n1. Merge Sort ");
     printf("\n2. Quick Sort ");
     printf("\n3. Heap Sort ");
     printf("\nEnter your choice: ");
     scanf("%d",&c);

     switch(c)
     {
        case 1:
            mergeSort(a,0,n);
            printArray(a,n);
            break;
        case 2:
            quickSort(a,0,n-1);
            printArray(a,n);
            break;
        case 3:
            heapSort(a,n);
            printArray(a,n);
            break;
        default:
            printf("\nINVALID CHOICE ");
     }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int partition (int arr[],int low,int high)
{
    int pivot=arr[high],swap,j;
    int i=(low - 1);

    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap=arr[i];
            arr[i]=arr[j];
            arr[j]=swap;
        }
    }

    swap=arr[i + 1];
    arr[i + 1]=arr[high];
    arr[high]=swap;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i,swap;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap=arr[i];
        arr[i]=arr[largest];
        arr[largest]=swap;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i,swap;;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i=n-1; i>=0; i--)
    {
        swap=arr[0];
        arr[0]=arr[i];
        arr[i]=swap;
        heapify(arr, i, 0);
    }
}
