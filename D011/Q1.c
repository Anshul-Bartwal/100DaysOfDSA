#include <stdio.h>
int main(){
    int r;
    int c;
    scanf("%d %d",&r,&c);
    int m1[r][c];
    int m2[r][c];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&m1[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&m2[i][j]);
        }
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",m1[i][j]+m2[i][j] );
        }
        printf("\n");

    }
    return 0;

}