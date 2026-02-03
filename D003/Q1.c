#include <stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter value to find: ");
    int key;
    scanf("%d",&key);
    for( int i=0;i<n;i++){
        if(arr[i] == key){
            printf("%d",i);
            return 0;
        }
    }
    printf("Not found");
    return 0;
    

}