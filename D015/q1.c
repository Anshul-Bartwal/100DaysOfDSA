#include <stdio.h>
int main(){
    int r;
    int c;
    scanf("%d %d",&r,&c);
    

    int m[r][c];



    for(int i=0;i<r;i++){
        for (int j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    int sum=0;
    if(r<=c){
        for(int i=0;i<r;i++){
            sum+=m[i][i];
        }

    }
    else{
        for(int i=0;i<c;i++){
            sum+=m[i][i];
        }
    }
    printf("%d",sum);
    return 0;
}
    
