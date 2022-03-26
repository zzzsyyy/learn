#include <stdio.h>

void Q1() {
  float val1, val2;
  char deg1, deg2;
  scanf("%f%c", &val1, &deg1);
  switch (deg1) {
  case 'F':
  case 'f':
    val2 = (val1 - 32) * 5 / 9.0;
    deg2 = 'C';
    break;
  case 'C':
  case 'c':
    val2 = 9 * val1 / 5.0 + 32;
    deg2 = 'F';
    break;
  }
  printf("%.2f%c = %.2f%c\n", val1, deg1, val2, deg2);
}

int main() {
  int a2, a3, a4;
  float a1, a5;
  scanf("%d%d%d", &a2, &a3, &a4);
  if (a2 + a4 == 2 * a3) {
    a1 = 2 * a2 - a3;
    a5 = 2 * a4 - a3;
    if (a2 * a4 == a3 * a3) {
      printf("等比&等差\n");
    } else {
      printf("等差\n");
    }
    printf("%d %d %d %d %d\n", (int)a1, a2, a3, a4, (int)a5);
  } else if (a2 * a4 == a3 * a3) {
    a1 = (float)a2 * a2 / a3;
    a5 = (float)a4 * a4 / a3;
    printf("等比\n");
    printf("%g %d %d %d %g\n", a1, a2, a3, a4, a5);
  } else {
    printf("不是等比等差\n");
  }
}
void Q3() {
  int fg;
  int i = 0;
  printf("请输入编码还是解码（0 or 1）");
  scanf("%d", &fg);getchar();
  char ipt[100] = {'\0'};
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