#include "stack_c.h"

int isEmpty_c(STACK_char *s) { return s->top == EMP; }

int isFull_c(STACK_char *s) { return s->top == s->capacity - 1; }

STACK_char *creatSTACK_c(int maxEles) {
  STACK_char *s;
  s = (STACK_char *)malloc(sizeof(STACK_char));
  s->array = (char *)malloc(sizeof(char) * maxEles);
  s->capacity = maxEles;
  makeEmpty_c(s);
  return s;
}

void disposeSTACK_c(STACK_char *s) {
  if (s != NULL) {
    free(s->array);
    free(s);
  }
}

void makeEmpty_c(STACK_char *s) {
  if (s != NULL) {
    s->top = EMP;
  }
}

bool push_c(STACK_char *s, char e) {
  if (isFull_c(s)) {
    printf("STACK_char Full!\n1");
    return false;
  } else {
    s->top++;
    s->array[s->top] = e;
    return true;
  }
}

bool pop_c(STACK_char *s, char *e) {
  if (isEmpty_c(s)) {
    printf("STACK_char Empty!\n");
    return false;
  } else {
    *e = s->array[s->top--];
    return true;
  }
}

bool top_c(STACK_char *s, char *e) {
  if (isEmpty_c(s)) {
    printf("STACK_char Empty!\n");
    return false;
  } else {
    *e = s->array[s->top];
    return true;
  }
}
