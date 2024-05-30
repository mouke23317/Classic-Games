#include <stdio.h>
#include "Minesweeper_Interface.h"
#include <stdlib.h>
void menu()
{
    printf("**********************************************************************\n");
    printf("*********************************1、开始游戏***************************\n");
    printf("*********************************2、退出游戏***************************\n");
    printf("**********************************************************************\n");
}

// 初始化矩阵
Mine** init_matrix(NUM rows, NUM cols, Mine* block_Matrix[])
{
    Mine init_rows;
    Mine init_cols;

    // 初始化 行指针
    block_Matrix = (Mine **)malloc(rows * (sizeof(Mine *)));
    for (init_rows = 0; init_rows < rows; init_rows++)
    {
        block_Matrix[init_rows] = (Mine *)malloc(cols * (sizeof(Mine)));

        for (init_cols = 0; init_cols < cols; init_cols++)
        {
            block_Matrix[init_rows][init_cols] = '*';
        }
    }
    return block_Matrix;
}

// 显示矩阵
void matrixDispaly(NUM rows, NUM cols, Mine *input_matrix[])
{
    Mine init_rows;
    Mine init_cols;
    //printf("%d", sizeof(short));
    printf("  ");
    for (init_cols = 0; init_cols < cols; init_cols++)
    {
        printf("%d ", init_cols);
    }
    printf("\n");

    for (init_rows = 0; init_rows < rows; init_rows++)
    {
        printf("%d ", init_rows);
        for (init_cols = 0; init_cols < cols; init_cols++)
        {
            printf("%c ", input_matrix[init_rows][init_cols]);
        }
        printf("\n");
    }
    
}
