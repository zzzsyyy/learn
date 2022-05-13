#include <stdio.h>

#define MAX 100

struct Matrix {
  int arr[MAX][MAX];
  int cols;
  int rows;
};

void DisplayMatrix(struct Matrix m) {
  for (int row = 0; row < m.rows; row++) {
    for (int col = 0; col < m.cols; col++) {
      printf("%d ", m.arr[row][col]);
    }
    printf("\n");
  }
}

void InputMatrix(struct Matrix *m) {
  printf("请输入行数：");
  scanf("%d", &m->rows);
  printf("请输入列数：");
  scanf("%d", &m->cols);
  printf("请输入矩阵：\n");
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      scanf("%d", &m->arr[i][j]);
    }
  }
}

int matrix_multi(struct Matrix m1, struct Matrix m2, struct Matrix *m3) {
  if (m1.rows != m2.cols) {
    return 0;
  } else {
    for (int i = 0; i < m1.rows; i++) {
      for (int j = 0; j < m1.cols; j++) {
        int ret = 0;
        for (int k = 0; k < m2.cols + 1; k++) {
          ret += m1.arr[i][k] * m2.arr[k][j];
        }
        m3->arr[i][j] = ret;
      }
    }
    m3->rows = m1.rows;
    m3->cols = m2.cols;
    return 1;
  }
}

int main() {
  int cols, rows;
  struct Matrix m1 = {{0}, 0, 0};
  struct Matrix m2 = {{0}, 0, 0};
  struct Matrix m3 = {{0}, 0, 0};
  printf("第一个矩阵\n");
  InputMatrix(&m1);
  printf("第二个矩阵\n");
  InputMatrix(&m2);
  if(matrix_multi(m1, m2, &m3)){
  printf("矩阵乘积为：\n");
  DisplayMatrix(m3);
  }else{
    printf("无法相乘！\n");
  }

}