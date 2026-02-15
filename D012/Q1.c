#include <stdio.h>
int main(){
    int r;
    int c;
    scanf("%d %d",&r,&c);
    if(r!=c){
        printf("Not Symmetric");
        return 1;
    }
    int m[r][c];


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }

    for(int i=0;i<r;i++){ //optimized to just check the triangle instead of whole matrix 
        for(int j=0;j<c-i;j++){

            if(m[i][j]!=m[j][i]){
                printf("Not Symmetric");
                return 1;
            }
        }
    }
    printf("Symmetric");
    return 0;


}