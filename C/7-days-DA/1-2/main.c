#include <stdio.h>

void Q1() {
  int a;
  printf("Please entre a ASCII value -> ");
  scanf("%d", &a);
  printf("That is %c\n", a);
}

void Q2() {
  double a;
  printf("Enter a floating-point value:");
  scanf("%lf", &a);
  printf("fixed-point notation: %lf\n", a);
  printf("expoential notation: %e\n", a);
  printf("p notation: %a\n", a);
}

void Q3() {
  float a;
  printf("Enter how-many cups:");
  scanf("%f", &a);
  printf("Equivalent to %.2f pints\n", a / 2);
  printf("Equivalent to %d flozs\n", (int)a * 8);
  printf("Equivalent to %d tbsps\n", (int)a * 16);
  printf("Equivalent to %d tsps\n", (int)a * 48);
}

int main(void) {
  printf("======Q1======\n");
  Q1();
  printf("======Q2======\n");
  Q2();
  printf("======Q3======\n");
  Q3();
}