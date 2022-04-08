#include <stdio.h>

int main() {
  int fg;
  int i = 0;
  printf("请输入编码还是解码（0 or 1）");
  scanf("%d", &fg);getchar();
  char ipt[100] = {'\0'};
  //实现对换行的过滤
  scanf("%[^\n]", ipt);
  if (fg == 0) {
    printf("编码后是：");
    while (ipt[i] != '\0') {
      char tmp = ipt[i++];
      if (tmp >= 'a' && tmp <= 'z') {
        printf("%c", (tmp - 'a' + 3) % 26 + 'a');
      }
      if (tmp >= 'A' && tmp <= 'Z') {
        printf("%c", (tmp - 'A' + 3) % 26 + 'A');
      }
      if (tmp == ' ') {
        printf(" ");
      }
    }
    printf("\n");
  } else if (fg == 1) {
    printf("解码后是：");
    while (ipt[i] != '\0') {
      char tmp = ipt[i++];
      if (tmp >= 'a' && tmp <= 'z') {
        printf("%c", 'z'-('z'-tmp+3) % 26);
      }
      if (tmp >= 'A' && tmp <= 'Z') {
        printf("%c", 'Z'-('Z'-tmp+3) % 26);
      }
      if (tmp == ' ') {
        printf(" ");
      }
    }
    printf("\n");
  }
}