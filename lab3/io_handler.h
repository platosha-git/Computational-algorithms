#ifndef IO_HANDLER_H
#define IO_HANDLER_H

void create_table_file(FILE *f, double ***table, int *num_points);
void create_table_console(double ***table, int *num_points);

void output_table(double **matr, int num_points);

#endif