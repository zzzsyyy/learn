#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define EMP -1

typedef double eleType;

typedef struct {
  eleType *array;
  int top;
  int capacity;
} STACK_double;

int isEmpty_d(STACK_double *s);
int isFull_d(STACK_double *s);
STACK_double *creatSTACK_d(int maxEles);
void disposeSTACK_d(STACK_double *s);
void makeEmpty_d(STACK_double *s);
bool pop_d(STACK_double *s, eleType *e);
bool push_d(STACK_double *s, eleType e);
