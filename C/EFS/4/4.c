#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

int gen_key();
void encryp(char*,FILE *fp, int key);
void dencryp(char*,FILE *fp, int key);
char okk(int argc, char *argv[]);
char en_ch(char ch, int key);
char *chnm(char *nm);

int main(int argc, char *argv[]) {
  FILE *fp=NULL;
  char *fnm;
  int key;
  char ch = okk(argc, argv);
  if ((fp = fopen(argv[2], "rw+")) != NULL) {
    const char *yf = argv[2];
    switch (ch) {
    case 'e':
      key = gen_key();
      fnm=chnm(argv[2]);
      encryp(fnm, fp, key);
      printf("%s", yf);
      printf("\nThe file's encryped into %s\n", fnm);
    case 'd':
      key = atoi(argv[3]);
      fnm=chnm(argv[2]);
      dencryp(fnm, fp, key);
      printf("\nThe file' dencryped into %s\n", fnm);
    }
  }
}

char okk(int argc, char *argv[]) {
  if (argc == 3 && strcmp(argv[1],"e")==0) {
    return 'e';
  } else if (argc == 4 && strcmp(argv[1],"d")==0) {
    return 'd';
  } else {
    exit(0);
  }
}

int gen_key(){
    srand((unsigned int) time(NULL));
    int n=rand()%26+1;
    printf("The key is %d\n", n);
    return n;
}

void encryp(char *f,FILE *fp, int key){
    char ch;
    char en[1000];
    FILE *p=NULL;
    char *enn=en;
    while((ch=fgetc(fp))!=EOF){
        ch=en_ch(ch, key);
        printf("%c",ch);
        *enn++=ch;
    }
    *enn++='\0';
    fclose(fp);
    p=fopen(f, "w+");
    fputs(en,p);
    fclose(p);
}

char en_ch(char ch, int key){
    if(ch>='a' && ch<='z'){
        return (ch-'a'+key)%26+'a';
    }
    if(ch>='A' && ch<='Z'){
        return (ch-'A'+key)%26+'A';
    }
    return ch;
}

char de_ch(char ch, int key){
    if(ch>='a' && ch<='z'){
        return 'z'-('z'-ch+key)%26;
    }
    if(ch>='A' && ch<='Z'){
        return 'z'-('z'-ch+key)%26;
    }
    return ch;
}

void dencryp(char *f,FILE *fp, int key){
    char ch;
    FILE *p=NULL;
    char en[1000];
    char *enn=en;
    while((ch=fgetc(fp))!=EOF){
        ch=de_ch(ch, key);
        printf("%c",ch);
        *enn++=ch;
    }
    *enn++='\0';
    fclose(fp);
    p=fopen(f, "w+");
    fputs(en, p);
    fclose(p);
}

char *chnm(char *nm){
    char *c = strrchr(nm, '.');
    int ind = c-nm+1;
    if (c==NULL){
        return strcat(nm,".en");
    }else{
        *c='\0';
        return strcat(nm,".en");
    }
}
