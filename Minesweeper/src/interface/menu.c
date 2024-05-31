#include <stdio.h>
#include "Minesweeper_Interface.h"
#include <stdlib.h>
void menu()
{
    printf("**********************************************************************\n");
    printf("*********************************1、开始游戏***************************\n");
    printf("*********************************0、退出游戏***************************\n");
    printf("**********************************************************************\n");
}

// 显示矩阵
void matrixDispaly(NUM rows, NUM cols, Mine *input_matrix[])
{
    Mine init_rows;
    Mine init_cols;
    // printf("%d", sizeof(short));
    printf("  ");
    for (init_cols = 0; init_cols < cols; init_cols++)
    {
        printf("%d ", init_cols + 1);
    }
    printf("\n");

    for (init_rows = 0; init_rows < rows; init_rows++)
    {
        printf("%d ", init_rows + 1);
        for (init_cols = 0; init_cols < cols; init_cols++)
        {
            printf("%c ", input_matrix[init_rows][init_cols]);
        }
        printf("\n");
    }
}
