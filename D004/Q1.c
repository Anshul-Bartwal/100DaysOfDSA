#include <stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){

        scanf("%d",&arr[i]);
    }

    int j=n-1;
    for (int i=0;i<n/2;i++){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;      
    }
    for(int k=0;k<n;k++){
        printf("%d ",arr[k]);
    }
    return 0;

}