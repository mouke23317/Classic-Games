#include <stdio.h>
#include "Minesweeper_Interface.h"
int main()
{
    Mine User_input;
    
    menu();
    scanf("%d", &User_input);
    do
    {
        NUM rows = 0;
        NUM cols = 0;
        Mine** block_Matrix = NULL;

        switch (User_input)
        {
        case 0:
            continue;
        case 1:
            printf("行区域：");
            scanf("%hd", &rows);
            printf("列区域：");
            scanf("%hd", &cols); // 自定义难度（矩阵大小）
            block_Matrix = init_matrix(rows, cols, block_Matrix);
            matrixDispaly(rows, cols, block_Matrix);
            break;

        default:
            break;
        }
        menu();
        scanf("%d", &User_input);
    } while (User_input != 0);
    return 0;
}