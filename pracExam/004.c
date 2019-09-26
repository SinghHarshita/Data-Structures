#include<stdio.h>
#define MAX 10

void insert(int a[], int val){
    int key = (val%MAX) - 1, i, f=0;

    if(a[key] == -1){
        a[key] = val;
        f=1;
    }
    else if(key<MAX-1){
        for(i=key+1;i<MAX;i++){
            if(a[i] == -1)
            {
                a[i] = val;
                f = 1;
                return;
            }
        }
    }
    else{
        for(i=0;i<key;i++){
            if(a[i] == -1)
            {
                a[i] = val;
                f = 1;
                return;
            }
        }
    }
    if(f == 0){
        System.out.println("\nArray is full! ");
    }
}

void display(int a[]){
    int i;
    for(i=0;i<MAX;i++){
        printf("\n%d",a[i]);
    }
}

int search(int a[], int key){
    int i;
    for(i=0;i<MAX;i++){
        if(a[i] == key)
            return i;
    }
    return -1;
}

void main(){
    int c, key, i;
    int a[MAX];

    for(i=0;i<MAX;i++){
        a[i] = -1;
    }

    do{
        printf("\nMENU:- \n1. Insert \n2. Search \n3. Display \n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&c);

        switch(c){
            case 0: break;
            case 1: printf("\nEnter the number: ");
                    scanf("%d",&key);
                    insert(a,key);
                    break;
            case 2: printf("\nEnter the number to be searched: ");
                    scanf("%d",&key);
                    i = search(a,key);
                    if(i!=-1){
                        printf("Element found!");
                    }
                    else{
                        printf("\nElement not found! ");
                    }
                    break;
            case 3: display(a);
                    break;
            default: printf("\nInvalid Choice! ");
        }
    }while(c!=0);
}
