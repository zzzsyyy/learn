#include "7.1/stack_c.h"
#include "7.1/stack_d.h"
#include <stdio.h>

eleType comValue(char *postexp) {
  STACK_double *num = creatSTACK_d(MAX);
  int i = 1, j = 0;
  double result;
  double a, b, c;
  char d[100] = {0};
  while (*postexp != '\0') {
    switch (*postexp) {
    case ' ':
      break;
    case '+':
      pop_d(num, &a);
      pop_d(num, &b);
      c = a + b;
      // printf("%g+%g=%g\n",a,b,c);
      push_d(num, c);
      break;
    case '-':
      pop_d(num, &a);
      pop_d(num, &b);
      c = b - a;
      // printf("%g-%g=%g\n",b,a,c);
      push_d(num, c);
      break;
    case '*':
      pop_d(num, &a);
      pop_d(num, &b);
      c = a * b;
      // printf("%g*%g=%g\n",a,b,c);
      push_d(num, c);
      break;
    case '/':
      pop_d(num, &a);
      pop_d(num, &b);
      if (c != 0) {
        c = b / a;
        // printf("%g\\%g=%g\n",b,a,c);
        push_d(num, c);
      } else {
        printf("除0错误！\n");
        exit(0);
      }
      break;
    default:
      j = 0;
      while (d[j] != '\0') {
        d[j++] = '\0';
      }
      j = 0;
      while ((*postexp >= '0' && *postexp <= '9') ||
             *postexp == '.' && *(postexp + 1) != ' ') {
        d[j++] = *postexp;
        postexp++;
      }
      c = atof(d);
      push_d(num, c);
    }
    postexp++;
  }
  pop_d(num, &result);
  return result;
}

void trans(char *exp, char postexp[]) {
  STACK_char *optr = creatSTACK_c(100);
  char e;
  int i = 0, j = 0;
  char d[100] = {0};
  while (*exp != '\0') {
    switch (*exp) {
    case ' ':
      exp++;
      break;
    case '(':
      push_c(optr, '(');
      exp++;
      break;
    case ')':
      pop_c(optr, &e);
      while (e != '(') {
        postexp[i++] = e;
        postexp[i++] = ' ';
        pop_c(optr, &e);
      }
      exp++;
      break;
    case '+':
    case '-':
      while (!isEmpty_c(optr)) {
        top_c(optr, &e);
        if (e == '(')
          break;
        else {
          postexp[i++] = e;
          postexp[i++] = ' ';
          pop_c(optr, &e);
        }
      }
      push_c(optr, *exp);
      exp++;
      break;
    case '*':
    case '/':
      while (!isEmpty_c(optr)) {
        top_c(optr, &e);
        if (e == '*' || e == '/') {
          postexp[i++] = e;
          postexp[i++] = ' ';
          pop_c(optr, &e);
        } else {
          break;
        }
      }
      push_c(optr, *exp);
      exp++;
      break;
    default:
      while ((*exp >= '0' && *exp <= '9') || *exp == '.') {
        postexp[i++] = *exp;
        // postexp[i++] = ' ';
        exp++;
      }
      postexp[i++] = ' ';
    }
  }
  while (!isEmpty_c(optr)) {
    pop_c(optr, &e);
    postexp[i++] = e;
  }
  postexp[i] = '\0';
}

int main() {
  char arr[100];
  printf("请输入表达式：");
  scanf("%s",arr);
  char arr2[100];
  trans(arr, arr2);
  printf("%s\n", arr2);
  double ret = comValue(arr2);
  printf("%g\n", ret);
}