#include <stdio.h>
#include "Input.h"

void eat_buffer()
{
    unsigned char ch = 0;
    do
    {
        ch = getchar();
    } while (ch != '\n');
}