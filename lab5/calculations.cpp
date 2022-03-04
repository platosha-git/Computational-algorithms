#include "calculations.h"
#define ftable "table.txt"

#include <stdlib.h>

void menu(double ***table, double **res)
{
    int n = 0;
    printf("Input n: \n");
    scanf("%d", &n);

    int m = 0;
    printf("Input m: \n");
    scanf("%d", &m);

    double t = 0;
    printf("Input parametr t: \n");
    scanf("%lf", &t);

    int chex = 0;
    printf("Choose external formula to integrate:\n");
    printf("Gauss.............1\n");
    printf("Simpson...........2\n");
    scanf("%d", &chex);

    int chin = 0;
    printf("Choose internal formula to integrate:\n");
    printf("Gauss.............1\n");
    printf("Simpson...........2\n");
    scanf("%d", &chin);

    double res = integrate(n, m, t, chin, chex);
    printf("The integral = %.5lf\n\n", res);
}
