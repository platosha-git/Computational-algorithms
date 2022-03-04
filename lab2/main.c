#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "io_handler.h"
#include "calculations.h"

#define ftable "table.txt"

int main(void)
{
	int x_points = 0;
	int y_points = 0;

	double *x_vector = NULL, *y_vector = NULL, **z_vector = NULL;

	printf("Create table\n\tfrom file............1\n");
	printf("\tfrom console.........2\n");

	int choose = 0;
	scanf("%d", &choose);

	if (choose == 1) {
		FILE *f = fopen(ftable, "r");
		if (!f) {
			printf("The table-file does not exist.\n");
			return 1;
		} else
			create_matr_file(f, &x_vector, &x_points, &y_vector, &y_points);
	}

	if (choose == 2)
		create_matr_console(&x_vector, &x_points, &y_vector, &y_points);

	z_vector = (double **)calloc(x_points * y_points, sizeof(double *));
	for (int i = 0; i < x_points; i++)
		z_vector[i] = (double *)calloc(y_points, sizeof(double));
	for (int i = 0; i < x_points; i++) {
		for (int j = 0; j < y_points; j++) {
			z_vector[i][j] = func(x_vector[i], y_vector[j]);
		}
	}

	printf("Table\n");
	output_table(x_vector, x_points, y_vector, y_points, z_vector);

	int n_x = 0;
	double x = 0;
	printf("Input nx: ");
	scanf("%d", &n_x);
	printf("Input argument x: ");
	scanf("%lf", &x);

	int n_y = 0;
	double y = 0;
	printf("Input ny: ");
	scanf("%d", &n_y);
	printf("Input argument y: ");
	scanf("%lf", &y);

	printf("\nFunction value = %.5lf\n\n", func(x, y));
	printf("Interpolation = %.5lf\n\n", interpolate(x_vector, x_points, y_vector, y_points, z_vector, x, y, n_x, n_y));
	for (int i = 0; i < x_points; i++)
		free(z_vector[i]);
	free(z_vector);
	free(x_vector);
	free(y_vector);
	return 0;
}