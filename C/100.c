#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

int run();

int main() {
  int count = 0;
  srand((unsigned)time(NULL));
  for (int i = 0; i < N; i++) {
    count += run();
  }
  printf("%lf", 1 - (double)count / N);
}

int run() {
  int arr[100] = {0};
  int num;
  int len = 0;
  int len_max = 0;
  for (int i = 0; i < 100; i++) {
    if (arr[i] != 0) {
      continue;
    } else {
      arr[i] = 1;
      len = 0;
      num = rand() % 100;
      if (num == i) {
        len = 1;
        continue;
      }
      while (num != i) {
        while (arr[num] == 1 && num != i) {
          num = rand() % 100;
        }
        arr[num] = 1;
        len++;
        // num=rand()%100;
      }
      len_max = (len_max > len) ? len_max : len;
    }
  }
  return len_max > 50;
}
