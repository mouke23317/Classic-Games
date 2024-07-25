#include <stdio.h>
#include <stdlib.h>
#include "Minesweeper_core.h"
#include "Input.h"
#include <malloc.h>

// 初始化矩阵
Mine **init_matrix(NUM rows, NUM cols)
{
    NUM init_rows;
    NUM init_cols;

    // 初始化 行指针
    Mine **block_Matrix = (Mine **)malloc(rows * (sizeof(Mine *)));
    if (block_Matrix == NULL)
    {
        printf("\n内存分配失败(行指针)。");
        return NULL;
    }

    // 初始化列空间
    for (init_rows = 0; init_rows < rows; init_rows++)
    {
        block_Matrix[init_rows] = (Mine *)malloc(cols * (sizeof(Mine)));
        // printf("%0x", &block_Matrix[init_rows]);

        if (block_Matrix[init_rows] == NULL)
        {
            recycle_memory(init_rows, &block_Matrix);
            printf("\n内存分配失败（列空间）。");
            return NULL;
        }

        for (init_cols = 0; init_cols < cols; init_cols++)
        {
            block_Matrix[init_rows][init_cols] = '*';
        }
    }
    return block_Matrix;
}

// 支持函数内直接对指针数组及其指向的空间直接操作
void recycle_memory(NUM rows, Mine ***block_Matrix)
{
    if ((block_Matrix == NULL || (*block_Matrix == NULL)))
    {
        return;
    }

    // 释放已初始化空间
    NUM recycle_rows;
    for (recycle_rows = 0; recycle_rows < rows; recycle_rows++)
    {
        if ((*block_Matrix)[recycle_rows] != NULL)
        {
            free((*block_Matrix)[recycle_rows]); // 指针数组每个元素指向空间释放
            (*block_Matrix)[recycle_rows] = NULL;
        }
    }
    free(*block_Matrix);
    *block_Matrix = NULL;
}

void set_mine(NUM random_cycle, NUM rows, NUM cols, Mine *input_matrix[], NUM* random_max)
{
    for (NUM i = 0; i < random_cycle; i++)
    {
        int random_NUM = rand() % (*random_max); // 将生成的随机数映射到区间0~rand_max - 1
        NUM random_row = random_NUM / cols; // 根据随机数查询行索引
        
        NUM random_col = random_NUM % cols; // 根据随机数查询列索引
        printf("%hd, %hd\n", random_row, random_col);

        input_matrix[random_row][random_col] = '&';
    }
}

void game()
{
    NUM rows = 0;
    NUM cols = 0;
    Mine **block_Matrix = NULL;
    NUM random_cycle;
    
    printf("行区域：");
    //自定义棋局大小
    while (custom_input(&rows) == 0 || rows == 0 || rows > MAX_SIZE)
        printf("非法输入，重输入行区域：");
    
    printf("列区域：");
    while (custom_input(&cols) == 0 || cols == 0 || cols > MAX_SIZE)
        printf("非法输入，重输入列区域：");
    
    block_Matrix = init_matrix(rows, cols);

    if (block_Matrix == NULL)
    {
        printf("游戏初始化失败");
        return;
    }

    matrixDispaly(rows, cols, block_Matrix); // 布雷前

    printf("\n请输入地雷数量。");
    NUM random_max = rows * cols;
    while (custom_input(&random_cycle) == 0 || random_cycle > random_max)
        printf("非法输入，请重新输入地雷数量，地雷数量是一个小于棋盘格数大小的值！");

    set_mine(random_cycle, rows, cols, block_Matrix, &random_max);
    matrixDispaly(rows, cols, block_Matrix); // 布雷后
    recycle_memory(rows, &block_Matrix);
    // printf("%0x", block_Matrix);
}