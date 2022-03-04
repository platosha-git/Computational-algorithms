#include <stdio.h>
#include <stdlib.h> 

#include "io_handler.h"

void create_table_file(FILE *f, double ***table, int *num_points)
{
	fscanf(f, "%d", num_points);
	(*table) = (double **)calloc(*num_points, sizeof(double *));
	for (int i = 0; i < *num_points; i++) {
		(*table)[i] = (double *)calloc(2, sizeof(double));
	}

	for (int i = 0; i < *num_points; i++) {
		fscanf(f, "%lf", &(*table)[i][0]);
		fscanf(f, "%lf", &(*table)[i][1]);
	}
}

void create_table_console(double ***table, int *num_points)
{
	printf("Input amount of points: ");
	scanf("%d", num_points);

	(*table) = (double **)calloc(*num_points * 2, sizeof(double *));
	for (int i = 0; i < *num_points; i++) {
		(*table)[i] = (double *)calloc(2, sizeof(double));
	}

	for (int i = 0; i < *num_points; i++) {
		printf("%d", i + 1);
		printf(" point\n\tx = ");
		scanf("%lf", &(*table)[i][0]);
		printf("\ty = ");
		scanf("%lf", &(*table)[i][1]);
	}
}

void output_table(double **table, int num_points)
{
	for (int i = 0; i < num_points; i++) {
		for (int j = 0; j < 2; j++)
			printf("%.3lf   ", table[i][j]);
		printf("\n");
	}
}