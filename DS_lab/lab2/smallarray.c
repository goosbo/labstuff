#include "stdio.h"

int smallestElement(int* arr,int n){
    int small = arr[0];
    int* ptr = arr;

    for(int i = 1; i < n; i++){
        if(small > *(ptr+i)) small = *(ptr+i);
    }
    return small;
}

int main(){
    int *arr, n,i;
    printf("enter number of elements: ");
    scanf("%d",&n);

    arr = (int*)malloc(n*sizeof(int));
    if(arr == NULL){
        printf("memory not allocated\n");
        return 1;
    }
    printf("enter %d elements: ",n);
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);

    printf("Smallest element: %d\n",smallestElement(arr,n));

    free(arr);
    return 0;
}
