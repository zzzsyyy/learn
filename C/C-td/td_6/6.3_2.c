#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define EMP -1
typedef int eleType;

typedef struct stack {
  eleType *array;
  int top;
  int capacity;
} STACK;

int isEmpty(STACK *s);               //是否为空
int isFull(STACK *s);                //是否已满
STACK *creatStack(int maxEles);      //创建堆栈
void disposeStack(STACK *s);         //释放堆栈
void makeEmpty(STACK *s);            //空栈
void pushStack(eleType e, STACK *s); //入栈
eleType top(STACK *s);               //返回栈顶元素
eleType popAndTop(STACK *S);         //出栈并返回栈顶元素

int isEmpty(STACK *s) { return s->top == EMP; }

int isFull(STACK *s) { return s->top == s->capacity - 1; }

STACK *creatStack(int maxEles) {
  STACK *s;
  s = (STACK *)malloc(sizeof(struct stack));
  s->array = (eleType *)malloc(sizeof(eleType) * maxEles);
  s->capacity = maxEles;
  makeEmpty(s);
  return s;
}

void disposeStack(STACK *s) {
  if (s != NULL) {
    free(s->array);
    free(s);
  }
}

void makeEmpty(STACK *s) {
  if (s != NULL) {
    s->top = EMP;
  }
}

void pushStack(eleType e, STACK *s) {
  if (!isFull(s)) {
    s->top++;
    s->array[s->top] = e;
  } else {
    printf("Stack Full!\n1");
  }
}

eleType top(STACK *s) {
  if (!isEmpty(s)) {
    return s->array[s->top];
  } else {
    printf("Stack Empty!\n");
    return 0;
  }
}

eleType popAndTop(STACK *s) {
  if (!isEmpty(s)) {
    return s->array[s->top--];
  } else {
    printf("Stack Empty!\n");
    return 0;
  }
}

void clear_buf(void) {
  char buf;
  while ((buf = getchar()) != '\n' && buf != EOF)
    ;
}

void info(STACK *s) {
  printf("容量%d栈顶%d\n", s->capacity, s->top);
  clear_buf();
  for (int i = 0; i <= s->top; i++) {
    printf("%d ", s->array[i]);
  }
  printf("\n");
}

int main() {
  int maxSize;
  eleType e;
  char sign;
  printf("n: new, i: push, p: pop, q: quit\n");
  while ((sign = getchar()) != 'q') {
    switch (sign) {
      clear_buf();
    case 'n':
      printf("请输入栈的大小：");
      scanf("%d", &maxSize);
      STACK *s = creatStack(maxSize);
      break;
    case 'i':
      scanf("%d", &e);
      pushStack(e, s);
      break;
    case 'p':
      popAndTop(s);
      break;
    case 'o':
      info(s);
    default:
      continue;
    }
    printf("i: input, o: ouput, p: pop, q: quit\n");
    clear_buf();
  }
}