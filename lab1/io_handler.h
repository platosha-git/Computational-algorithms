#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include "constants.h"

void create_matr(FILE *f, double (*matr)[max_degree], int n);
void output_table(double (*matr)[max_degree], int points_amount);

#endif