#include <stdio.h>
#include <stdlib.h>

int pgcd_1(int a, int b);
int pgcd_2(int a, int b);
void arrg(int *a, int *b);

int main(int argc, char **argv) {
  int n = atoi(argv[1]) * (atoi(argv[1]) > 0 ? 1 : -1);
  int m = atoi(argv[2]) * (atoi(argv[2]) > 0 ? 1 : -1);
  int p_1 = pgcd_1(m, n);
  int p_2 = pgcd_2(m, n);
  printf("p_1=%d\n", p_1);
  printf("p_2=%d\n", p_2);
  return 0;
}

int pgcd_1(int a, int b) {
  arrg(&a, &b);
  if (0 == b)
    return a;
  else
    return pgcd_1(a - a / b * b, b);
}

//using recursion
int pgcd_2(int a, int b) {
  while (0 != a && 0 != b) {
    arrg(&a, &b);
    a -= a / b * b;
  }
  return 0 == a ? b : a;
}

void arrg(int *a, int *b) {
  if (*a < *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
}