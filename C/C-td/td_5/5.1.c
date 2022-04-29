#include <stdio.h>

int ststr(char *s1, char *s2) {
  int count = 0;
  char *cur = s1;
  while (cur && '\0' != *cur) {
    char *p1 = cur;
    char *p2 = s2;
    while (p1 && p2 && *p1 == *p2 && '\0' != *p1) {
      p1++;
      p2++;
    }
    if (*p2 == '\0') {
      count++;
      printf("%ld ", cur - s1 + 1);
      cur = p1;
    } else {
      cur +=p1-cur+1;
    }
  }
  return count;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Please enter two strings!\n");
    return 0;
  };
  int ret = ststr(argv[1], argv[2]);
  printf("\n%d\n", ret);
}