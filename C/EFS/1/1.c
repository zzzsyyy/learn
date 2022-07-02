#include<stdio.h>

int main(){
   int nm=0, fg=0;
    printf("");
    scanf("%d", &nm);
    if ((0!=nm%100 && 0==nm%4)||(0!=nm%400 && 0==nm%100)){
        printf("该年份 %d 为闰年\n", nm);
    }else{
        printf("该年份 %d 为非闰年\n", nm);
    }
}