#include "basefunc.h"
#include <cmath>

double (*BaseFunc(double t))()
{
    double (*resbtw)() = 2 * cos(x) / (1 - (sin(x) * sin(x)) * (cos(y) * cos(y)));
    double (*res)() = (1 - exp(-t * resbtw(x, y))) * cos(x) * sin(x);
    return res;
}

int max_degree = 0;

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




