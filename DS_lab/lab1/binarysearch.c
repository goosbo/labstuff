#include <stdio.h>

int binarySearch(int a[],int n, int k){
    int l = 0, r = n-1,m;
    while(l <= r){
        m = (l+r)/2;
        if(a[m] > k)r = m-1;
        else if(a[m] < k)l = m+1;
        else return m+1;
    }
    return -1;
}

int main()
{
    int n,arr[100],i,k,pos;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter a sorted array of %d elements: ",n);
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    printf("Enter key: ");
    scanf("%d",&k);
    pos = binarySearch(arr,n,k);
    if(pos != -1)printf("element found at position %d",pos);
    else printf("element not found");
}
