#include <stdio.h>
#include <string.h>

#define MAX 1000

enum Gender { MALE, FEMALE, OTHER };

struct Student {
  char name[20];
  int genger;
  float score;
};

int printScoreByName(struct Student stus[], int num) {
  char name[20];
  printf("请输入同学的姓名:");
  scanf("%s", name);
  for (int i = 0; i < num; i++) {
    if (!strcmp(stus[i].name, name)) {
      printf("%s同学成绩为%g\n", name,stus[i].score);
      return 1;
    }
  }
  printf("未找到该同学\n");
  return 0;
}

void printAvegScore(struct Student stus[], int num) {
  float sum = 0;
  for (int i = 0; i < num; i++) {
    sum += stus[i].score;
  }
  printf("%d位同学的平均成绩为%g\n",num,sum/num);
}

void inputInfo(struct Student *stu) {
  printf("name:");
  scanf("%s", stu->name);
  printf("gender (0:female, 1: male, 2:other):");
  scanf("%d", &stu->genger);
  printf("score:");
  scanf("%f", &stu->score);
}

int main() {
  struct Student stus[MAX] = {"", -1, -1};
  int num;
  char name[20];
  printf("请输入学生总数：");
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    printf("第%d位同学\n", i + 1);
    inputInfo(&stus[i]);
  }
  printAvegScore(stus, num);
  printScoreByName(stus, num);
}
