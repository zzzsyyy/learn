#include "game.h"

void menu ()
{
    printf("*******   扫雷   *********\n");
    printf("*******1.play   0.exit*********\n");
}

void game()
{
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    DisplayBoard(show, ROW, COL);
    SetMine(mine, ROW, COL);
    FindMine(mine, show, ROW, COL);
}

void test ()
{
    int input = 0;
    srand((unsigned int)time(NULL));

    do
    {
        menu();
        printf("请选择：>");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf ("选择错误，重新选择\n");
            break;
        }
    }while (input);
}

int main ()
{
    test();
    return 0;
}
