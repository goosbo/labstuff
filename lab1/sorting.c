#include <stdio.h>

void bubbleSort(int a[],int n){
    int temp;
    for(int i = 0; i < n-1;i++){
        for(int j = 0; j < n-i-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(int a[],int n){
    int temp,minIndex;
    for(int i = 0; i < n-1; i++){
        minIndex = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[minIndex]) minIndex = j;
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

void insertionSort(int a[],int n){
    for(int i = 1; i < n; i++){
        int j = i-1, key = a[i];
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main()
{
    int n,arr[100],i,c;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter an array of %d elements: ",n);
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    printf("Choose the algorithm to use for sorting\nEnter 1 for bubble sort, 2 for selection sort and 3 for insertion sort: ");
    scanf("%d",&c);
    switch(c){
        case 1:
        bubbleSort(arr,n);
        printf("Elements sorted with bubble sort:\n");
        break;
        case 2:
        selectionSort(arr,n);
        printf("Elements sorted with selection sort:\n");
        break;
        case 3:
        insertionSort(arr,n);
        printf("Elements sorted with insertion sort:\n");
        break;
        default:
        printf("invalid input");
        exit(0);
    }
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
