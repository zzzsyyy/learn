#include <stdio.h>

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
