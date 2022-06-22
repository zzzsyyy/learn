#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MIN 1
#define MAX 1000

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void arr_print(int len, int arr[]) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void arr_sort_1(int len, int arr[]) {
  for (int i = 0; i < len - 1; i++) {
    int min = i;
    for (int j = i + 1; j < len; j++) {
      min = arr[min] > arr[j] ? j : min;
    }
    if (min != i) {
      swap(&arr[i], &arr[min]);
    }
  }
}

// using recursion
void arr_sort_2(int len, int arr[]) {
  if (len != 1) {
    int min = 0;
    for (int i = 0; i < len; i++) {
      min = arr[i] < arr[min] ? i : min;
    }
    if (0 != min) {
      swap(&arr[0], &arr[min]);
    }
    arr_sort_2(len - 1, &arr[1]);
  }
}

void arr_init(int len, int arr[], int min, int max) {
  srand((unsigned)time(NULL));
  for (int i = 0; i < len; i++) {
    arr[i] = rand() % (max - min + 1) + min;
  }
}

int main() {
  int arr[N] = {0};
  arr_init(N, arr, MIN, MAX);
  printf("before sort: ");
  arr_print(N, arr);
  arr_sort_2(N, arr);
  printf("after sort:  ");
  arr_print(N, arr);
  return 0;
}