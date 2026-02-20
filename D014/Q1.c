#include <stdio.h>
#include <stdbool.h>
int main(){
    int r;
    int c;
    scanf("%d %d",&r,&c);
    if(r!=c){
        printf("Not Identity Matrix");
        return 1;
    }

    int m[r][c];

    bool isI=true;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&m[i][j]);
            if(i==j && m[i][j]!=1 ){
                isI=false;
            }else if(i!=j && m[i][j]!=0){
                isI=false;
            }
        }
    }

    printf("%s",isI ? "Identity":"Not Identity");

}