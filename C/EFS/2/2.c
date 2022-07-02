#include <stdio.h>

int count=0;

void pt(int i, int j) {
  for (int k = i; k <= j; k++) {
    if (k == j) {
      printf("%d", k);
    } else {
      printf("%d + ", k);
    }
  }
  printf("\n");
  count++;
}

int main() {
  int num;
  scanf("%d", &num);
  int n = num;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    num = n;
    for (int j = i; j <= (n + 1) / 2; j++) {
      num -= j;
      if (0 == num && j > i) {
        // printf("\n%d  %d\n", i, j);
        printf("%d = ", n);
        pt(i, j);
      }
    }
  }
  printf("总计%d种组合方式\n",count);
}