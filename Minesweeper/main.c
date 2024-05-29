#include <stdio.h>
#include "Minesweeper_Interface.h"
int main ()
{
    Mine User_inoput;   
    menu();
    scanf("%d", &User_inoput);

    do
    {
        switch (User_inoput)
        {
        case 2:
            break;
        case 1:
            menu();
            break;
        
        default:
            break;
        }
        scanf("%d", &User_inoput);
    } while (User_inoput != 0);
    return 0;
}