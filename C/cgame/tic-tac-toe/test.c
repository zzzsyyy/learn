#include "game.h"

void menu()
{
    printf("********   三子棋   *********\n");
    printf("********1.play   0.exit*******\n");
}

void game()
{
    char ret = 0;
    char board[ROW][COL] = {0};
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    while (1)
    {
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }
    if (ret == '*')
        printf("玩家赢！\n");
    else if (ret == '#')
        printf("电脑赢！\n");
    else
        printf("平局！\n");
}

void test()
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
            printf("三子棋\n");
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，请重新选择！\n");
            break;
        }
    } while (input);
}

int main()
{
    test();
    return 0;
}
