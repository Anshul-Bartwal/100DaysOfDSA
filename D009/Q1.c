#include <stdio.h>
void rev(char *str){
    if(*str == '\0'){
        return; 
    }
    rev(str+1);
    printf("%c",*str);

}
int main(){
    char str[100];
    scanf("%s",str);
    char *p = str;
    rev(p);
    return 0;

}