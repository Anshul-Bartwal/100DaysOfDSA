#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    scanf("%s",str);
    int left=0;
    int right = strlen(str)-1;
    while(left<right){

        if(str[left]!=str[right]){
            printf("NO");
            return 1;
        }
        left++;
        right--;

    }
    printf("YES");
    return 0;
}