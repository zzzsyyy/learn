#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float get_rand_num_by_MB() {
  static int Q = 0;
  double ret;
  // Marsaglia-Bray 算法
  double v1, v2, s;
  do {
    v1 = (rand() / ((double)RAND_MAX)) * 2.0 - 1.0;
    v2 = (rand() / ((double)RAND_MAX)) * 2.0 - 1.0;
    s = v1 * v1 + v2 * v2;
  } while (s >= 1.0 || s == 0.0);
  s = sqrt(-2.0 * log(s) / s);
  Q = 1-Q;
  return Q?v1 * s:v2*s;
}

int main() {
  int n = 1000, max = 0, m = 1;
  double arr[] = {2.0,  1.8,  1.6,  1.4,  1.2,  1.0,  0.8,
                  0.6,  0.4,  0.2,  0.0,  -0.2, -0.4, -0.6,
                  -0.8, -1.0, -1.2, -1.4, -1.6, -1.8, -2.0};
  srand((unsigned)time(NULL)); //随机数初始化
  int l = sizeof(arr) / sizeof(arr[0]);
  int times[l + 1];
  for (int i = 0; i < l + 1; i++)
    times[i] = 0;
  for (int i = 0; i < n; i++) {
    double a = get_rand_num_by_MB();
    for (int j = 0; j < l; j++) {
      if (a > arr[j]) {
        times[l - j]++;
        break;
      } else if (a <= arr[l - 1]) {
        times[0]++;
        break;
      }
    }
  }

  //   for (int i=1;i<21;i++){
  //       printf("%d\n",times[i]);
  //   }
  //获取出现最多的次数 && 位数
  for (int i = 1; i < l; i++) {
    max = (times[i] > max) ? times[i] : max;
  }
  // printf("max=%d\n",max);
  while (max / 10 > 0) {
    max /= 10;
    m *= 10;
  }
  //   printf("m=%d\n",m);
  //打印统计数据
  for (int i = 1; i < l; i++) {
    int num = times[i] / m;
    for (int j = 0; j < num; j++) {
      printf("*");
    }
    printf("\n");
  }
}