#include <stdio.h>
#include "Input.h"

//缓冲区还剩下'\n'的时候就返回1，否则返回0
unsigned short eat_buffer()
{
    unsigned char ch = 0;
    unsigned short eat_time = 0;
    do
    {
        ch = getchar();
        eat_time++;
    } while (ch != '\n');
    if ((eat_time - 1) != 0)
        return 0;
    else
        return 1;
}