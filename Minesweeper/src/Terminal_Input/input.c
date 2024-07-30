#include <stdio.h>
#include <Minesweeper_Interface.h>
#include "Input.h"

Mine select_input(Mine *input_Elem)
{
    Mine ch;
    Mine ch_next;
    // 条件：限制输入0 - 9 的数字，转化为ASCII为48～57
    while (((ch = getchar()) != EOF && (ch != '\n')) && ((ch < '0') || (ch > '1')))
    {
        while ((ch = getchar()) != '\n')
            ;
        printf("\n您需要按照选项前的数字进行选择。");
    }

    if (((ch == EOF) || ch == '\n') || ((ch < '0') || (ch > '1')))
    {
        printf("\n输入为空，请重新输入：");
        return INPUTERROR;
    }

    // 检查是否是一个纯粹的'1' 或 '0'
    if ((ch_next = getchar()) != '\n')
    {
        while ((ch = getchar()) != '\n')
            ;
        printf("\n请输入一个纯粹的选项前数字：");
        return INPUTERROR;
    }

    *input_Elem = ch;
    return 1;
}

NUM custom_input(NUM *input_num)
{
    // 自定义难度（矩阵大小）
    NUM result = 0;
    NUM eat_time = 0;
        /* code */
    result = scanf("%hu", input_num);
    // 吃掉缓冲区
    eat_time = eat_buffer();
    return result && eat_time;
}