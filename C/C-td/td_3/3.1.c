#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n, max = 0, m = 1;
  int times[26] = {0};
  srand((unsigned)time(NULL)); //随机数初始化

  n = 10000;
  for (int i = 0; i < n; i++) {
    char ch = 'a' + rand() % 26;
    times[ch - 'a']++;
  }
  //获取出现最多的次数 && 位数
  for (int i = 0; i < 26; i++) {
    max = (times[i] > max) ? times[i] : max;
  }
  printf("%d", max);
  while (max / 10 > 0) {
    max = max / 10;
    m *= 10;
  }
  printf("m=%d\n", m);
  //打印统计数据
  for (int i = 0; i < 26; i++) {
    int num = times[i] / m;
    printf("%d", times[i]);
    printf("the current %c show: ", i + 'a');
    for (int j = 0; j < num; j++) {
      printf("*");
    }
    printf("\n");
  }
}
