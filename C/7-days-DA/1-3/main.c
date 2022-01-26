#include <float.h>
#include <stdio.h>
#include <string.h>

#define MAXN 100

void Q1() {
  char stra[MAXN];
  char strb[MAXN];
  scanf("%s%s", stra, strb);
  int a = strlen(stra);
  int b = strlen(strb);
  printf("%s %s\n", stra, strb);
  printf("%*d%*d\n", a, a, b + 1, b);
  printf("%s %s\n", stra, strb);
  printf("%-*d%-*d\n", a + 1, a, b, b);
}

void Q2() {
  double a = 1.0 / 3.0;
  float b = 1.0 / 3.0;
  printf("double 6: %.6f\ndouble 12: %.12f\ndouble 16: %.16f\n", a, a, a);
  printf("float 6: %.6f\nfloat 12: %.12f\nfloat 16: %.16f\n", b, b, b);
  printf("FLT_DIG: %d\nDBL_DIG: %d\n", FLT_DIG, DBL_DIG);
}

void Q3() {
  const float Gal = 3.785;
  const float Mile = 1.609;
  float a, b;
  printf("输入里程数（英里）:"), scanf("%f", &a);
  printf("输入耗油量（加仑）:"), scanf("%f", &b);
  printf("美式：%.1f 英里/加仑\n", a / b);
  printf("欧式：%.1f 升/百公里\n", b / Mile / a * Gal * 100);
}

int main(void) {
  printf("======Q1======\n");
  Q1();
  printf("======Q2======\n");
  Q2();
  printf("======Q3======\n");
  Q3();
}