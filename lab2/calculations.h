#ifndef CALCULATIONS_H
#define CALCULATIONS_H

double func(double x, double y);

double interpolate(double *x_vector, int x_points, 
					double *y_vector, int y_points, 
					double **z_vector, double x, double y, int n_x, int n_y);
void point_in_table(double *arg_vector, double arg, int *begin, int *end, int n, int points_amount);
void print_table(int x, int y, double **table);

#endif