#include "stdio.h"
#include "stdlib.h"

void product(int** a, int** b, int** c,int ma, int na,int mb, int nb){
    for(int i = 0; i < ma; i++){
        for(int j = 0; j < nb; j++){
            *(*(c+i)+j) = 0;
            for(int k = 0; k < mb; k++){
                *(*(c+i)+j) += (*(*(a+i)+k)) * (*(*(b+k)+j));
            }
        }
    }
}

int main(){
    int **a,**b,**c,ma,na,mb,nb,i,j;
    printf("Enter order of first matrix(m n): ");
    scanf("%d %d",&ma,&na);
    a = (int**)malloc(ma*sizeof(int*));
    if(a == NULL){
        printf("memory not allocated\n");
        return 1;
    }
    for(i = 0; i < ma; i++){
        *(a+i) = (int*)malloc(na*sizeof(int));
        if(*(a+i) == NULL){
            printf("memory not allocated\n");
            return 1;
        }
    }

    printf("Enter first array elements: \n");
    for(i = 0; i < ma; i++){
        for(j = 0; j < na; j++){
            scanf("%d",*(a+i)+j);
        }
    }

    printf("Enter order of second matrix(m n): ");
    scanf("%d %d",&mb,&nb);
    b = (int**)malloc(mb*sizeof(int*));
    if(b == NULL){
        printf("memory not allocated\n");
        return 1;
    }
    for(i = 0; i < mb; i++){
        *(b+i) = (int*)malloc(nb*sizeof(int));
        if(*(b+i) == NULL){
            printf("memory not allocated\n");
            return 1;
        }
    }

    printf("Enter second array elements: \n");
    for(i = 0; i < mb; i++){
        for(j = 0; j < nb; j++){
            scanf("%d",*(b+i)+j);
        }
    }

    if(na != mb) {
        printf("invalid matrix order\n");
        return 1;
    }
    c = (int**)malloc(ma*sizeof(int*));
    if(c == NULL){
        printf("memory not allocated\n");
        return 1;
    }
    for(int i = 0; i < ma; i++){
        *(c+i) = (int*)malloc(nb*sizeof(int));
        if(*(c+i) == NULL){
            printf("memory not allocated\n");
            return 1;
        }
    }
    product(a,b,c,ma,na,mb,nb);
    printf("first array: \n");
    for(i = 0; i < ma; i++){
        for(j = 0; j < na; j++)printf("%d ",*(*(a+i)+j));
        printf("\n");
    }
    printf("second array: \n");
    for(i = 0; i < mb; i++){
        for(j = 0; j < nb; j++)printf("%d ",*(*(b+i)+j));
        printf("\n");
    }
    printf("product array: \n");
    for(i = 0; i < ma; i++){
        for(j = 0; j < nb; j++)printf("%d ",*(*(c+i)+j));
        printf("\n");
    }
    free(a);
    free(b);
    free(c);
    return 0;
}
