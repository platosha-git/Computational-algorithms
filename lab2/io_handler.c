#include <stdio.h>
#include <stdlib.h> 

#include "io_handler.h"

void create_matr_file(FILE *f, double **x_vector, int *x_points, double **y_vector, int *y_points)
{
	fscanf(f, "%d", x_points);
	fscanf(f, "%d", y_points);

	*x_vector = (double *)calloc(*x_points, sizeof(double));
	*y_vector = (double *)calloc(*y_points, sizeof(double));

	for (int i = 0; i < *x_points; i++)
		fscanf(f, "%lf", &(*x_vector)[i]);

	for (int i = 0; i < *y_points; i++)
		fscanf(f, "%lf", &(*y_vector)[i]);
}

void create_matr_console(double **x_vector, int *x_points, double **y_vector, int *y_points)
{
	printf("Input amount of x points: ");
	scanf("%d", x_points);
	printf("Input amount of y points: ");
	scanf("%d", y_points);

	*x_vector = (double *)calloc(*x_points, sizeof(double));
	*y_vector = (double *)calloc(*y_points, sizeof(double));
	
	for (int i = 0; i < *x_points; i++)
		(*x_vector)[i] = 0;
	printf("X vector\n");
	for (int i = 0; i < *x_points; i++) {
		printf("%d", i + 1);
		printf(" point\n\tx = ");
		scanf("%lf", &(*x_vector)[i]);
	}

	for (int i = 0; i < *y_points; i++)
		(*y_vector)[i] = 0;
	printf("Y vector\n");
	for (int i = 0; i < *y_points; i++) {
		printf("%d", i + 1);
		printf(" point\n\ty = ");
		scanf("%lf", &(*y_vector)[i]);
	}
}

void output_table(double *x_vector, int x_points, double *y_vector, int y_points, double **z_vector)
{
	printf("x\\y   | ");
	for (int j = 0; j < y_points; j++) {
		printf("%.3lf  ", y_vector[j]);
	}
	printf("\n");
	for (int i = 0; i < y_points; i++)
		printf("--------");
	for (int i = 0; i < x_points; i++) {
		printf("\n%.3lf | ", x_vector[i]);
		for (int j = 0; j < y_points; j++) {
			printf("%.3lf ", z_vector[i][j]);
		}
	}
	printf("\n");
}