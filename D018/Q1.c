#include <stdio.h> 
int main(){
    int n;

    
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

    }
    int k;
    //only for k<n
    scanf("%d",&k);
    while(k>n){
        k-=n;
    }
    int startIndex=n-k;
    int index=startIndex;
    while(index!=n){
        printf("%d ",arr[index++]);
    }
    index=0;
    while(index!=startIndex){
        printf("%d ",arr[index++]);
    }
    return 0;



}