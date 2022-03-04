#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "constants.h"

double func(double x);

double interpolate(double (*table)[max_degree], int n, double x, int points_amount);
void point_in_table(double (*table)[max_degree], double x, int *x_begin, int *x_end, int n, int points_amount);

double half_division(double (*table)[max_degree], double x, int points_amount);
double inverse_interpolate(double (*table)[max_degree], int n, double x, int points_amount);
void sort_table(double (*table)[max_degree], int points_amount);

#endif