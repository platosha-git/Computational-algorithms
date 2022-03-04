#include <stdio.h>
#include <stdlib.h> 

#include "calculations.h"

double func(double x)
{
	return x * x * x;
}

double interpolate(double **table, int num_points, double x)
{
	int x_i = 0;
	for (int i = 0; i < num_points - 1; i++) {
		if (table[i][0] <= x && table[i + 1][0] > x) {
			x_i = i;
			break;
		}
	}

	double *h = calloc(num_points, sizeof(double));
	for (int i = 1; i < num_points; i++)
		h[i] = table[i][0] - table[i - 1][0];

	double *a = calloc(num_points, sizeof(double));
	for (int i = 1; i < num_points; i++)
		a[i] = h[i - 1];

	double *b = calloc(num_points, sizeof(double));
	for (int i = 2; i < num_points; i++)
		b[i] = -4 * h[i - 1];

	double *d = calloc(num_points, sizeof(double));
	for (int i = 1; i < num_points; i++)
		d[i] = h[i];

	double *f = calloc(num_points, sizeof(double));
	for (int i = 2; i < num_points; i++)
		f[i] = -3 * ((table[i][1] - table[i - 1][1]) / h[i] - (table[i - 1][1] - table[i - 2][1]) / h[i - 1]);

	
//Прямой ход
	double *e = calloc(num_points + 1, sizeof(double));
	double *n = calloc(num_points + 1, sizeof(double));
	
	for (int i = 2; i < num_points; i++)
	{
		e[i + 1] = d[i] / (b[i] - a[i] * e[i]);
		n[i + 1] = (a[i] * n[i] + f[i]) / (b[i] - a[i] * e[i]);
	}


//Обратный ход
	for (int i = 1; i < num_points; i++)
		a[i] = table[i - 1][1];

	double *c = calloc(num_points + 1, sizeof(double));
	for (int i = num_points - 1; i > -1; i--)
		c[i] = e[i + 1] * c[i + 1] + n[i + 1];

	for (int i = 1; i < num_points; i++)
		b[i] = (table[i][1] - table[i - 1][1]) / h[i] - h[i] * (c[i + 1] + 2 * c[i]) / 3;

	for (int i = 1; i < num_points; i++)
		d[i] = (c[i + 1] - c[i]) / (3 * h[i]);

//q(x) = ai + bi(x - x(i-1)) + ci(x - x(i-1))^2 + di(x - x(i-1))^3
	printf("Koef\n");
	printf("A = %f\n", a[x_i]);
	printf("B = %f\n", b[x_i]);
	printf("C = %f\n", c[x_i]);
	printf("D = %f\n", d[x_i]);

	double y = a[x_i];
	y += b[x_i] * (x - table[x_i - 1][0]);
	y += c[x_i] * (x - table[x_i - 1][0]) * (x - table[x_i - 1][0]);
	y += d[x_i] * (x - table[x_i - 1][0]) * (x - table[x_i - 1][0]) * (x - table[x_i - 1][0]);

	free(h); free(a); free(b); free(d); free(f);
	return y;
}
