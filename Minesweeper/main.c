#include <stdio.h>
#include "Minesweeper_Interface.h"
#include "Minesweeper_core.h"
#include "Input.h"
int main()
{
    Mine User_input;

    menu();
    while (select_input(&User_input) == 0)
        ;
    do
    {
        NUM rows = 0;
        NUM cols = 0;
        Mine **block_Matrix = NULL;

        switch (User_input)
        {
        case '0':
            continue;
        case '1':
            printf("行区域：");
            scanf("%hd", &rows);
            getchar();
            printf("列区域：");
            scanf("%hd", &cols); // 自定义难度（矩阵大小）
            getchar();
            block_Matrix = init_matrix(rows, cols);
            if (block_Matrix == NULL)
            {
                printf("游戏初始化失败");
                break;
            }
            matrixDispaly(rows, cols, block_Matrix);
            recycle_memory(rows, &block_Matrix);
            printf("%0x", block_Matrix);
            break;

        default:
            break;
        }
        menu();
        while (select_input(&User_input) == 0)
            ;
    } while (User_input != '0');
    return 0;
}