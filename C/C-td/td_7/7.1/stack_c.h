#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define EMP -1

typedef struct {
  char *array;
  int top;
  int capacity;
} STACK_char;

int isEmpty_c(STACK_char *s);
int isFull_c(STACK_char *s);
STACK_char *creatSTACK_c(int maxEles);
void disposeSTACK_c(STACK_char *s);
void makeEmpty_c(STACK_char *s);
bool pop_c(STACK_char *s, char *e);
bool push_c(STACK_char *s, char e);
bool top_c(STACK_char *s, char *e);