#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "io_handler.h"
#include "calculations.h"

#define ftable "table.txt"

int main(void)
{
	int num_points = 0;
	double **table = NULL;

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
			create_table_file(f, &table, &num_points);
	}

	if (choose == 2)
		create_table_console(&table, &num_points);
	
	printf("Table\n");
	output_table(table, num_points);

	double x = 0;
	printf("Input argument x: \n");
	scanf("%lf", &x);


	printf("\nFunction value = %.5lf\n\n", func(x));
	printf("Interpolation = %.5lf\n\n", interpolate(table, num_points, x));

	return 0;
}



