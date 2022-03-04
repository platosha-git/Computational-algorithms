#include "calculations.h"
#define ftable "table.txt"

#include <stdlib.h>

void menu(double ***table, double **res)
{
    int num_points = 0;
    double *p = nullptr;

    int choose = 0;
    while (choose != 5) {
        printf("Create table\n\tfrom file............1\n");
        printf("\tfrom console.........2\n");
        printf("Change function.......3\n");
        printf("\tweight...............4\n");
        printf("Input degree..........5\n");

        scanf("%d", &choose);

        if (choose == 1) {
            FILE *f = fopen(ftable, "r");
            if (!f) {
                printf("The table-file does not exist.\n");
                exit(1);
            } else {
                create_table_file(f, table, &p, &num_points);
            }
        }

        if (choose == 2)
            create_table_console(table, &p, &num_points);

        if (choose == 3)
            change_table(table, &num_points);

        if (choose == 4)
            change_weight(&p, num_points);
    }

    int degree = 0;
    scanf("%d", &degree);

    *res = squaring(*table, p, num_points, degree);

    delete(p);
}
