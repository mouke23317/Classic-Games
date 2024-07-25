#ifndef MENU_H_
#define MENU_H_
#define INPUTERROR 0
#define MAX_SIZE 100

typedef unsigned short NUM; //循环数用
typedef unsigned char Mine; //雷格表示、部分更小数字需求

void menu();
void matrixDispaly(NUM rows, NUM cols, Mine* input_matrix[]);
#endif