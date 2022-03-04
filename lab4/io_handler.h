#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include <stdio.h>

void create_table_file(FILE *f, double ***table, double **p, int *num_points);
void create_table_console(double ***table, double **p, int *num_points);

void change_table(double ***table, int *num_points);
void change_weight(double **p, int num_points);

void output_table(double **table, double *p, int num_points);

void output_vector(double *v, int n);
void output_matr(double **matr, int s, int c);

#endif // IO_HANDLER_H
