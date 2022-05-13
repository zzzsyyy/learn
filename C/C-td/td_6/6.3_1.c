#include <stdio.h>
#include <stdlib.h>

#define MAX (5 + 1)

int QUEUE[MAX];
int push(int);
int pop(void);
void info(void);
void clear_buf(void);

int head = 0;
int tail = 0;

int main() {
  int value;
  char sign;

  int value_return;
  printf("i: input, o: ouput, p: pop, q: quit\n");
  while ((sign = getchar()) != 'q') {
    switch (sign) {
      clear_buf();
    case 'i':
      scanf("%d", &value);
      push(value);
      break;
    case 'p':
      value_return = pop();
    //   info();
      break;
    case 'o':
      info();
    default:
      continue;
    }
    printf("i: input, o: ouput, p: pop, q: quit\n");
    clear_buf();
  }
}

void info(void) {
  int used = (tail - head + MAX) % MAX;
  printf("长度 %d\t;已用 %d\t;还有 %d\n", MAX - 1, used, MAX - 1 - used);
  printf("t=%d\th=%d\n", tail, head);
  for (int i = 0; i < used; i++) {
    printf("%d ", QUEUE[(head+i)%MAX]);
  }
  printf("\n");
}
int push(int value) {
  if ((tail + 1) % MAX == head) {
    printf("队列已满\n");
    return tail;
  }
  QUEUE[tail] = value;
  tail = (tail + 1) % MAX;
  return tail;
}
int pop(void) {
  if (head == tail) {
    printf("队列为空\n");
    return head;
  }
  printf("%d ", QUEUE[head]);
  head = (head + 1) % MAX;
  return head;
}
void clear_buf(void) {
  char buf;
  while ((buf = getchar()) != '\n' && buf != EOF)
    ;
}
