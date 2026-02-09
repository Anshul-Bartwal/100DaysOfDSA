#include <stdio.h>
int memo[1000] = {0};
int fib(int n){
    if (n==0){
        return n;
    }
    if(n==1)return 1;

    if (memo[n] !=0){
        return memo[n];
    }
    
    memo[n]= (fib(n-1)+fib(n-2));
    return memo[n];
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fib(n));
    return 0;
}