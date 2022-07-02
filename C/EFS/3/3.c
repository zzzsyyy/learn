#include<stdio.h>
#include<string.h>
void sr(char *ch, int *arr);

int main(){
    char ch1[100], ch2[100];
    int arr1[26]={0}, arr2[26]={0};
    int n=1;
    printf("输入第一个字符串：");
    scanf("%s", ch1);
    printf("输入第二个字符串：");
    scanf("%s", ch2);
    sr(ch1,arr1);
    sr(ch2,arr2);
    for(int i=0;i<26;i++){
        if(arr1[i]!=arr2[i]){
            printf("non");
            return 0;
        }
    }
    printf("%s 和 %s 符合条件，为Anagram\n",ch1,ch2);
}

void sr(char *ch, int *arr){
    for (int i=0;i<strlen(ch);i++){
        arr[ch[i]-'a']=1;
    }
}