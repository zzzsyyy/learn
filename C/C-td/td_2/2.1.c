#include <stdio.h>

int main(void) {
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
