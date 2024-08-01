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

//二维数组重整为一维，可以入库
Mine** reshape(NUM rows, NUM cols, NUM matrix_size, Mine* input_matrix[])
{
     NUM copy_counter = 0;
     Mine** copy_arr = (Mine**)malloc(matrix_size * sizeof(Mine*));
    if (copy_arr == NULL)
    {
        printf("复制失败，强制退出");
        return NULL;
    }
    
    //行遍历
    for (NUM i = 0; i < rows; i++)
    {
        //列遍历
        for (NUM j = 0; j < cols; j++, copy_counter++)
        {
            copy_arr[copy_counter] = &(input_matrix[i][j]);
        }
    }
    return copy_arr;
}
NUM set_mine(NUM random_cycle, NUM rows, NUM cols, Mine *input_matrix[], NUM *random_max)
{
    NUM copy_counter = 0;
    Mine* copy_temp = NULL;
    Mine** reshaped_matrix = reshape(rows, cols, *random_max, input_matrix);
    if (reshaped_matrix == NULL)
        return 0;
    
    //测试
    //*(copy_matrix[99]) = '&';

    //棋盘的所有的元素都将参与洗牌
    for (NUM i = 0; i < *random_max; i++)
    {
        int random_NUM = rand() % (*random_max); // 将生成的随机数映射到区间0~rand_max - 1
        // NUM random_row = random_NUM / cols;      // 根据随机数查询行索引
        // NUM random_col = random_NUM % cols; // 根据随机数查询列索引

        //根据上面生成的映射后随机数排列原始指针数列，调转地址排列，
        copy_temp = reshaped_matrix[random_NUM];
        reshaped_matrix[random_NUM] = reshaped_matrix[i];
        reshaped_matrix[i] = copy_temp;
    }
    
    //序列中的前面random_cycle个元素埋雷
    for (NUM i = 0; i < random_cycle; i++)
        *(reshaped_matrix[i]) = '&';
    
    for (NUM i = random_cycle; i < *random_max; i++)
    {
        *(reshaped_matrix[i]) = '0';
    }
    
    free(reshaped_matrix);
    return 1;
}  

//设置边界提示，命中率确定算法中心，命中低的做中心
void boundary_tips(NUM Mine_NUM, NUM rows, NUM cols, NUM matrix_size, Mine *input_matrix[])
{
    //降维打击
    Mine** reshaped_matrix = reshape(rows, cols, matrix_size, input_matrix);
    if(reshaped_matrix == NULL)
        return;
    if (Mine_NUM >= matrix_size / 2)
    {
        for (NUM i = 0; i < matrix_size; i++)
        {
            NUM up_basic = i - cols;
            NUM down_basic = i + cols;
            NUM right_basic = i + 1;
            NUM left_basic = i - 1;
            //区分9种类型的中心扩散九宫格
            //判断上述的四个拓展位是否为负数
            //是负数，不运算，不是负数就运算该拓展位相关的
            //2024/8/1开发暂停记录，已同步github
            
            
            
        }
    }
}

void game()
{
    NUM rows = 0;
    NUM cols = 0;
    Mine **block_Matrix = NULL;
    NUM random_cycle;

    // 自定义棋局大小
    printf("行区域：");
    while (custom_input(&rows) == 0 || rows == 0 || rows > MAX_SIZE)
        printf("非法输入，行区域是一个小于100的纯阿拉伯数字，重输入行区域：");

    printf("列区域：");
    while (custom_input(&cols) == 0 || cols == 0 || cols > MAX_SIZE)
        printf("非法输入，列区域是一个小于100的纯阿拉伯数字，重输入列区域：");

    // 按照上述棋局大小分配内存空间
    block_Matrix = init_matrix(rows, cols);

    if (block_Matrix == NULL)
    {
        printf("游戏初始化失败");
        return;
    }
    matrixDispaly(rows, cols, block_Matrix); // 布雷前

    //自定义地雷数量
    printf("\n请输入地雷数量。");
    NUM random_max = rows * cols;
    while (custom_input(&random_cycle) == 0 || random_cycle >= random_max)
        printf("非法输入，请重新输入地雷数量，地雷数量是一个小于棋盘格数大小的值！");

    //根据地雷数量确定哈希表最大质数，并完成随机数到哈希表的映射
    //eratosthenes(random_cycle);

    if (set_mine(random_cycle, rows, cols, block_Matrix, &random_max) == 0)
    {
        printf("游戏布雷失败，本轮强制退出！");
        return ;
    }
    
    matrixDispaly(rows, cols, block_Matrix); // 布雷后
    recycle_memory(rows, &block_Matrix);
    // printf("%0x", block_Matrix);
}