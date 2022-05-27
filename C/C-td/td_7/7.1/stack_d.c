#include "stack_d.h"

int isEmpty_d(STACK_double *s) { return s->top == EMP; }

int isFull_d(STACK_double *s) { return s->top == s->capacity - 1; }

STACK_double *creatSTACK_d(int maxEles) {
  STACK_double *s;
  s = (STACK_double *)malloc(sizeof(STACK_double));
  s->array = (eleType *)malloc(sizeof(eleType) * maxEles);
  s->capacity = maxEles;
  makeEmpty_d(s);
  return s;
}

void disposeSTACK_d(STACK_double *s) {
  if (s != NULL) {
    free(s->array);
    free(s);
  }
}

void makeEmpty_d(STACK_double *s) {
  if (s != NULL) {
    s->top = EMP;
  }
}

bool push_d(STACK_double *s, eleType e) {
  if (isFull_d(s)) {
    printf("STACK_double Full!\n1");
    return false;
  } else {
    s->top++;
    s->array[s->top] = e;
    return true;
  }
}

bool pop_d(STACK_double *s, eleType *e) {
  if (isEmpty_d(s)) {
    printf("STACK_double Empty!\n");
    return false;
  } else {
    *e = s->array[s->top--];
    return true;
  }
}
