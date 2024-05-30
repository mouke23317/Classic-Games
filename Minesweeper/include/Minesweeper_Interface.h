#ifndef MENU_H_
#define MENU_H_
typedef short NUM;
typedef unsigned char Mine;
void menu();
Mine** init_matrix(NUM rows, NUM cols, Mine* block_Matrix[]);
void matrixDispaly(NUM rows, NUM cols, Mine* input_matrix[]);
#endif