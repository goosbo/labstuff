#include <stdio.h>
int main()
{
    int n,arr[100],i,k,found = 0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter an array of %d elements: ",n);
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    printf("Enter key: ");
    scanf("%d",&k);
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            found = 1;
            printf("Found element %d at index %d",k,i);
            break;
        }

    }
    if(!found)printf("did not find element");
}
