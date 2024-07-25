#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Minesweeper_Interface.h"
#include "Minesweeper_core.h"
#include "Input.h"

int main()
{
    Mine User_input;

    //随机数种子（用时间戳作为种子生成器起点）
    srand((unsigned int)time(NULL));
    menu();
    while (select_input(&User_input) == 0)
        ;
    do
    {
        switch (User_input)
        {
        case '0':
            continue;

        case '1':
            game();
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


