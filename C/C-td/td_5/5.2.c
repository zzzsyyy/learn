#include <stdio.h>

char *ststr(char *s1, char *s2, char *s3) {
  char static ret[1000] = {0};
  char *rett = ret;
  char *cur = s1;
  while (cur && '\0' != *cur) {
    char *p1 = cur;
    char *p2 = s2;
    while (p1 && p2 && '\0' != *p1 && *p1 == *p2) {
      p1++, p2++;
    }
    if (*p2 == '\0') {
      char *p3 = s3;
      while ((*rett++ = *p3++) != '\0')
        ;
      rett--;
      cur = p1;
    } else {
      *rett++ = *cur++;
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Please enter three strings!\n");
    return 0;
  }
  char *rettt = ststr(argv[1], argv[2], argv[3]);
  printf("%s\n", rettt);
}
