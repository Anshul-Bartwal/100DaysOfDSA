#include <stdio.h>
int main(){
    int r;
    int c;
    scanf("%d %d",&r,&c);

    int m[r][c];


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }
    int top=0,bottom=r-1;
    int left=0,right=c-1;
    while(top<=bottom && left<=right){
        //right
        for(int i=left;i<=right;i++){
            printf("%d ",m[top][i]);
        }
        top++;

        //down
        for(int i=top;i<=bottom;i++){
            printf("%d ",m[i][right]);
        }
        right--;


        if(top<=bottom){
            // left
            for(int i=right;i>=left;i--){
                printf("%d ",m[bottom][i]);
            }
            bottom--;
        }
        if(left <= right){
            //up
            for(int i = bottom; i >= top; i--){
                printf("%d ", m[i][left]);
            }
            left++;
        }
    }return 0;
}




    // int stepArr[4] ={1,c,-1,-c};
    // int el[2]={r,c-1};
    // int e=0;
    // int *arr;
    // arr = &m[0][0];

    // int step=0;
    // int iter=1;

    // for(int i=0;i<r*c;i++){
        
    //     if(iter==2){
    //         if(step==3){
    //             step=0;
    //         }else{
    //             step++;
    //         }
    //     }
    //     if(i==el[e]){
    //         if(e==1){
    //             e=0;
    //         }else{
    //             e++;
    //         }
    //         iter++;

    //     }
        
    //     printf("%d ", *arr);
    //     arr = arr + stepArr[step];
        
    // }
    // return 0;
