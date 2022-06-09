#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int fr(char *s1, char *s2);

int main(int argc, char *argv[]){
  int i = 0, count = 0;
  char wt[1000], voc[40], ch;
  FILE *fp;

  if (argc!=2){
    printf("please use `%s filename`", argv[0]);
    exit(0);
  }

  if ((fp=fopen(argv[1], "r"))==NULL) {
    printf("Fail to open %s", argv[1]);
    exit(1);
  }

  printf("please input the string you want:");
  scanf("%s", voc);
  while (fgets(wt, 1000, fp)!=NULL){
    count+=fr(wt, voc);
  }
  printf("il y a %d %s in this file", count, voc);
}

int fr(char *s1, char *s2){
  int n=0, l1=0, l2=0;
  char *p=s1;

  l1=strlen(p);
  l2=strlen(s2);
  while(l1>=l2){
    p=strstr(p,s2);
    if(p!=0){
      n++;
      p+=l1;
    }else break;
    l1=strlen(p);
  }
  return n;
}
