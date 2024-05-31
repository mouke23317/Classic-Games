#include <stdio.h>
#include "Minesweeper_Interface.h"
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
        printf("%0x", &block_Matrix[init_rows]);

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

//支持函数内直接对指针数组及其指向的空间直接操作
void recycle_memory(NUM rows, Mine*** block_Matrix)
{
    if((block_Matrix == NULL || (*block_Matrix == NULL)))
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