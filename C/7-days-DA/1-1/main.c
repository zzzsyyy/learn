#include <stdio.h>
#include <stdlib.h>

//=====//
void br() { printf("Brazil, Russia"); }
void ic() { printf("India, China"); }
//====//

void Q1() {
  char lastName[] = "Zhang";
  char firstName[] = "Shanying";
  printf("%s %s\n", lastName, firstName);
  printf("%s\n", lastName);
  printf("%s\n", firstName);
  printf("%s ", lastName);
  printf("%s", firstName);
}

void Q2(char *ne) {
  int DDD = 0, ry = 0;
  int y = 0, m = 0, d = 0;
  int yy = 2022, mm = 1, dd = 24;
  int M[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int i = 0; i <= 3; i++) {
    y = y * 10 + (int)ne[i] - 48;
  };
  for (int i = 4; i <= 5; i++) {
    m = m * 10 + (int)ne[i] - 48;
  }
  for (int i = 6; i <= 7; i++) {
    d = d * 10 + (int)ne[i] - 48;
  }
  while (y < yy || m < mm || d <= dd) {
    ry = y + 1, d++;
    if (m == 12 && d == 32) {
      m = 1, d = 1, y++;
    }
    if (d == M[m - 1] + 1) {
      d = 1, m++;
    }
    if (ry == y && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)) {
      DDD += 1;
    }
    DDD++;
  }
  printf("%d", DDD - 1);
}

void Q3() {
  br(), printf(", "),ic(), printf("\n");
  ic(), printf("\n");
  br(), printf("\n");
}

int main(void) {
  printf("======Q1======\n");
  Q1();
  printf("\n======Q2======\n");
  Q2("20011202");
  printf("\n======Q3======\n");
  Q3();
}
