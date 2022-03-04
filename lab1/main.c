#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "io_handler.h"
#include "calculations.h"
#include "constants.h"

int main(void)
{
	int points_amount = 7;
	double table[points_amount][max_degree];

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
			create_matr(f, table, points_amount);
	}

	if (choose == 2) {
		printf("Input amount of points: ");
		scanf("%d", &points_amount);
		for (int i = 0; i < points_amount; i++) {
			for (int j = 0; j < max_degree; j++)
				table[i][j] = 0;
		}

		for (int i = 0; i < points_amount; i++) {
			printf("%d", i + 1);
			printf(" point\n\tx = ");
			scanf("%lf", &table[i][0]);
			printf("\ty = ");
			scanf("%lf", &table[i][1]);
		}
	}
	
	int n = 0;
	printf("Input polinomial degree: \n");
	scanf("%d", &n);
	
	double x = 0;
	printf("Input argument x: \n");
	scanf("%lf", &x);


	printf("\nFunction value = %.5lf\n\n", func(x));

	printf("Interpolation = %.5lf\n\n", interpolate(table, n, x, points_amount));
	printf("Half division = %.5lf\n", half_division(table, x, points_amount));
	printf("Inverse interpolation = %.5lf\n\n", inverse_interpolate(table, n, x, points_amount));
	return 0;
}



