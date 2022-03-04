#ifndef IO_HANDLER_H
#define IO_HANDLER_H

void create_matr_file(FILE *f, double **x_vector, int *x_points, double **y_vector, int *y_points);
void create_matr_console(double **x_vector, int *x_points, double **y_vector, int *y_points);
void output_table(double *x_vector, int x_points, double *y_vector, int y_points, double **z_vector);

#endif