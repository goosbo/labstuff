#include "stdio.h"
#include "stdlib.h"
int min_index(int* a,int j,int n){
    if(j>n){
        exit(0);
    }
    if(j == n-1){
        return j;
    }
    int nxt_min = min_index(a,j+1,n);
    if(*(a+j) <= *(a+nxt_min)) return j;
    else return nxt_min;
}

void selection_sort(int* a, int n,int i){
    if(i == n-1){
        return;
    }
    int* ptr = a;
    int min_idx = min_index(ptr,i,n);
    if(*(ptr+i)>*(ptr+min_idx)){
        int temp = *(ptr+i);
        *(ptr+i) = *(ptr+min_idx);
        *(ptr+min_idx) = temp;
    }
    selection_sort(a,n,i+1);
}

int main(){
    int *arr,n,i;
    printf("enter no. of elements: ");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int));
    if(arr == NULL){
        printf("memory not allocated\n");
        return 1;
    }
    printf("enter %d elements: ",n);
    for(i = 0; i < n; i++)scanf("%d",arr+i);
    selection_sort(arr,n,0);
    printf("sorted elements: \n");
    for(int i = 0; i < n; i++)printf("%d ",*(arr+i));
    printf("\n");
    free(arr);
    return 0;
}
