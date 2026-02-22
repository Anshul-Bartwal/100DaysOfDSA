#include <stdio.h>
#include <limits.h>
int main(){
    int n;

    scanf("%d", &n);
    int arr[n];
    int max=INT_MIN;
    int min=INT_MAX;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    printf("%d %d",max,min);
    return 0;



}