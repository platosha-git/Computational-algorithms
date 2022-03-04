#include <stdio.h>
#include <stdlib.h> 

#include "calculations.h"

double func(double x)
{
	return x * x * x;
}

////////////////////////Интерполяция полиномом Ньютона///////////////////////

double interpolate(double (*table)[max_degree], int n, double x, int points_amount)
{
	int x_begin = 0, x_end = 0;
	point_in_table(table, x, &x_begin, &x_end, n, points_amount);
	
	for (int j = 2; j < n + 2; j++) {
		for (int i = x_begin; i < x_end - j + 1; i++)
			table[i][j] = (table[i][j - 1] - table[i + 1][j - 1]) / (table[i][0] - table[i + j - 1][0]);
	}

	double res = table[x_begin][1];
	double temp = x - table[x_begin][0];
	for (int j = 2; j < n + 3; j++) {
		res += temp * table[x_begin][j];
		temp *= (x - table[x_begin + j - 1][0]);
	}
	return res;
}

void point_in_table(double (*table)[max_degree], double x, int *x_begin, int *x_end, int n, int points_amount)
{
	int xi = 0;
	for (int i = 0; i < points_amount - 1; i++) {
		if (table[i][0] <= x && table[i + 1][0] > x) {
			xi = i;
			break;
		}
	}

	int points_around = (n + 1) / 2;

	if (xi + points_around + 1 > points_amount) {
		(*x_end) = points_amount;
		(*x_begin) = points_amount - n;
	}
	else {
		if (xi < points_around) {
			(*x_begin) = 0;
			(*x_end) = n;
		}
		else {
			(*x_begin) = xi - points_around;
			(*x_end) = (*x_begin) + n + 1;
		}
	}
}


////////////////////////Поиск корня методом половинного деления////////////

double half_division(double (*table)[max_degree], double x, int points_amount)
{
	int i = 0;
	for (i = 0; i < points_amount - 1; i++) {
		if (table[i][1] * table[i + 1][1] <= 0)
			break;
	}

	double res = 0;
	if (table[i][1] == 0)
		res = table[i][1];
	else if (table[i + 1][1] == 0)
		res = table[i + 1][1];
	else {
		double a = table[i][0];
		double b = table[i + 1][0];
		double c = 0;
		c = (a + b) / 2;
		while ((b - a) / x > eps) {
			c = (a + b) / 2;
			if (func(a) * func(c) < 0)
				b = c;
			else
				a = c;
		}
		res = c;
	}
	return res;
}

/////////////////////Обратная интерполяция////////////////////////////

double inverse_interpolate(double (*table)[max_degree], int n, double x, int points_amount)
{
	for (int i = 0; i < points_amount; i++)
		for (int j = 2; j < max_degree; j++)
			table[i][j] = 0;

	for (int i = 0; i < points_amount; i++) {
		double temp = table[i][0];
		table[i][0] = table[i][1];
		table[i][1] = temp;
	}
	sort_table(table, points_amount);
	double res = interpolate(table, n, 0, points_amount);
	return res;
}

void sort_table(double (*table)[max_degree], int points_amount)
{
	for (int i = 0; i < points_amount - 1; i++) {
		if (table[i][0] > table[i + 1][0]) {
			double tempx = table[i + 1][0];
			double tempy = table[i + 1][1];

			table[i + 1][0] = table[i][0];
			table[i + 1][1] = table[i][1];

			table[i][0] = tempx;
			table[i][1] = tempy;
		}
	}
}