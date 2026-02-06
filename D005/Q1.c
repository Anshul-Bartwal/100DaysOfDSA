#include <stdio.h>

int main() {
    int n1, n2;

    
    scanf("%d", &n1);

    int arr1[n1];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int res[n1+n2];
    int i=0,j=0,k=0;
    while (i < n1 && j<n2 ){
        if(arr1[i] < arr2[j]){
            res[k++] = arr1[i++];
        }else{
            res[k++] = arr2[j++];
        }
    }

    while (i < n1) res[k++] = arr1[i++];
    while (j<n2) res[k++] = arr2[j++];
    for (int i = 0; i < k; i++) {
        printf("%d ", res[i]);
 
    }
    printf("\n");
    
    return 0;
} 