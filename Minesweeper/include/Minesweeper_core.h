#ifndef CORE_H_
#define CORE_H_
#include "Minesweeper_Interface.h"

Mine **init_matrix(NUM rows, NUM cols);
void recycle_memory(NUM rows, Mine*** block_Matrix);
NUM set_mine(NUM random_cycle, NUM rows, NUM cols, Mine *input_matrix[], NUM* random_max);
void game();
Mine** reshape(NUM rows, NUM cols, NUM matrix_size, Mine* input_matrix[]);
#endif