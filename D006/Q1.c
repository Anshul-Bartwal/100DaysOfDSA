#include <stdio.h>
int main(){
    int n;

    
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int ans[n];
    int ansIndex=0;
    ans[0]=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] == ans[ansIndex]){
            continue;
        }
        ans[++ansIndex]=arr[i];


    }

    for (int i = 0; i < ansIndex+1; i++) {
        printf("%d ", ans[i]);
 
    }
    return 0;
}