#include <stdio.h>
#include <stdlib.h> 

#include "calculations.h"

double func(double x, double y)
{
	return x * x + y * y;
}

////////////////////////Интерполяция полиномом Ньютона///////////////////////

double interpolate(double *x_vector, int x_points, 
					double *y_vector, int y_points, 
					double **z_vector, double x, double y, int n_x, int n_y)
{
	int x_begin = 0, x_end = 0;
	point_in_table(x_vector, x, &x_begin, &x_end, n_x + 1, x_points);	

	int y_begin = 0, y_end = 0;
	point_in_table(y_vector, y, &y_begin, &y_end, n_y + 1, y_points);

	double *table_vector = (double *)calloc(n_y + 1, sizeof(double));

	double **table = (double **)calloc((n_x + 1) * (n_x + 2), sizeof(double *));
	for (int i = 0; i < n_x + 1; i++)
		table[i] = (double *)calloc(n_x + 2, sizeof(double)); 

	for (int k = 0; k < n_y + 1; k++) {
		for (int i = x_begin; i < x_end; i++) {
			table[i - x_begin][0] = x_vector[i];
			table[i - x_begin][1] = z_vector[i][k + y_begin];
		}
		for (int j = 2; j < n_x + 2; j++) {
			for (int i = 0; i < n_x - j + 2; i++)
				table[i][j] = (table[i][j - 1] - table[i + 1][j - 1]) / (table[i][0] - table[i + j - 1][0]);
		}
		double res = table[0][1];
		double temp = x - table[0][0];
		for (int j = 2; j < n_x + 2; j++) {
			res += temp * table[0][j];
			temp *= (x - table[j - 1][0]);
		}
		//print_table(n_x + 1, n_x + 2, table);
		table_vector[k] = res;
	}

	for (int i = 0; i < n_x + 1; i++)
		free(table[i]);
	free(table);

	double **res_table = (double **)calloc((n_y + 1) * (n_y + 2), sizeof(double *));
	for (int i = 0; i < n_y + 1; i++)
		res_table[i] = (double *)calloc(n_y + 2, sizeof(double)); 

	for (int i = y_begin; i < y_end; i++) {
		res_table[i - y_begin][0] = y_vector[i];
		res_table[i - y_begin][1] = table_vector[i - y_begin];
	}

	for (int j = 2; j < n_y + 2; j++) {
		for (int i = 0; i < n_y - j + 2; i++)
			res_table[i][j] = (res_table[i][j - 1] - res_table[i + 1][j - 1]) / (res_table[i][0] - res_table[i + j - 1][0]);
	}

	double res = res_table[0][1];
	double temp = y - res_table[0][0];
	for (int j = 2; j < n_y + 2; j++) {
		res += temp * res_table[0][j];
		temp *= (y - res_table[j - 1][0]);
	}

	//print_table(n_y + 1, n_y + 2, res_table);

	for (int i = 0; i < n_y + 1; i++)
		free(res_table[i]);
	free(res_table);

	free(table_vector);
	return res;
}

void point_in_table(double *arg_vector, double arg, int *begin, int *end, int n, int points_amount)
{
	int argi = 0;
	for (int i = 0; i < points_amount - 1; i++) {
		if (arg_vector[i] <= arg && arg_vector[i + 1] > arg) {
			argi = i;
			break;
		}
	}

	int points_around = n / 2;
	if (argi + points_around + 1 > points_amount) {
		(*end) = points_amount;
		(*begin) = points_amount - n;
	}
	else {
		if (argi < points_around) {
			(*begin) = 0;
			(*end) = n;
		}
		else {
			(*begin) = argi - points_around + 1;
			(*end) = (*begin) + n;
		}
	}
}

void print_table(int x, int y, double **table) 
{
	printf("Current table\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			printf("%lf ", table[i][j]);
		printf("\n");
	}
}