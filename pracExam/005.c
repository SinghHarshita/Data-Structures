#include<stdio.h>
#define MAX 10

void display(int a[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("\n%d ",a[i]);
    }
}

void bubbleSort(int a[], int n){
    int i, j, temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n){
    int i, j, temp, min;

    for(i=0;i<n;i++){
        min = i;

        for(j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertionSort(int a[], int n){
    int i, j, temp;

    for(i=1; i<n; i++){
        temp = a[i];
        j=i-1;

        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void mergeSort(int a[], int low, int high){

    int mid = (low+high)/2;

    mergeSort(a,low,mid);
    mergeSort(a,m+1,high);
    merge(a,low,mid,high);
}

void merge(int arr[], int l, int m, int r){
    int i,j,k;
    int n1 = m-l+1, n2 = r-m;
    int left[n1], right[n2];

    for(i=0;i<n1;i++)
        left[i] = arr[i+l];
    for(j=0;j<n2;j++)
        right[j] = arr[m+1+j];

    i=0;j=0;k=l;

    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = left[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k] = right[j];
        k++;
        j++;
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high], temp, j, i = low-1;

    for(j=low;j<high-1;j++){
        if(arr[j]<=pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[j];
    arr[j] = temp;
    return i+1;
}

void quickSort(int a[], int low, int high){
    int pos;
    if(low<high){
        pos = partition(a,low,high);
        quickSort(a,low,pos);
        quickSort(a,pos+1,high);
    }
}

void heapify(int ar[], int n, int i){

    int largest = i, temp;
    int l = 2*i+1, r = 2*i+2;

    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }
    else if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=i){
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr,n,largest);
    }
}

void heapSort(int a[], int n){
    int i, temp;

    for(i=n/2-1;i>=0;i++){
        heapify(a,n,i);
    }

    for(i=n-1; i>=0; i--){
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a,i,0);
    }
}


void main(){
    int a[10], c, n=10, i;

    do{
        printf("\nMENU:- \n1. Bubble Sort \n2.Selection Sort \n3. Insertion Sort \n4. Merge Sort \n5. Quick Sort \n6. Heap Sort \n0.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&c);

        printf("\nEnter the numbers one by one: ");
        for(i=0;i<n;i++){
            scanf("\n%d",&a[i]);
        }

        switch(c){
            case 0: break;
            case 1: bubbleSort(a,n); display(a,n); break;
            case 2: selectionSort(a,n); display(a,n); break;
            case 3: insertionSort(a,n); display(a,n); break;
            case 4: mergeSort(a,0,n); display(a,n); break;
            case 5: quickSort(a,0,n); display(a,n); break;
            case 6: heapSort(a,n); display(a,n); break;
            default: printf("\nInvalid Choice! ");
        }
    }while(c!=0);
}
