#include<stdio.h>
#include<stdlib.h>

int hnt(int n){
    if (1==n){
        return 1;
    }else{
        return 2*hnt(n-1)+1;
    }
}

int main(int argc, char** argv){
    int ret = hnt(atoi(argv[1]));
    printf("%d\n",ret);
    return 0;
}