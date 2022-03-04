#include <stdio.h>
#include <stdlib.h> 

#include "io_handler.h"

void create_matr(FILE *f, double (*matr)[max_degree], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < max_degree; j++)
			matr[i][j] = 0;
	}

	for (int i = 0; i < n; i++) {
		fscanf(f, "%lf", &matr[i][0]);
		fscanf(f, "%lf", &matr[i][1]);
	}
}

void output_table(double (*matr)[max_degree], int points_amount)
{
	for (int i = 0; i < points_amount; i++) {
		for (int j = 0; j < max_degree; j++)
			printf("%.3lf   ", matr[i][j]);
		printf("\n");
	}
}