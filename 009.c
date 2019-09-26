#include<stdio.h>
#define max 10

int binarySearch(int a[], int l,int h, int num)
{
    int mid=(l+h)/2;

    if(a[mid]==num)
    {
        return mid+1;
    }
    else if(l>h)
        return 0;
    else if(a[mid]<num)
        binarySearch(a,mid+1,h,num);
    else if(a[mid]>num)
        binarySearch(a,l,mid-1,num);
}
