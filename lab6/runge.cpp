#include "runge.h"

double* LeftRunge(double y[], int num, double step)
{
    double *res = new double[num];
    res[0] = -1;
    res[1] = -1;

    for (int i = 2; i < num; i++) {
        res[i] = 2 * (y[i] - y[i - 1]) / step;
        res[i] -= (y[i] - y[i - 2]) / (2 * step);
    }
    return res;
}

double* RightRunge(double y[], int num, double step)
{
    double *res = new double[num];
    for (int i = 0; i < num - 2; i++) {
        res[i] = 2 * (y[i + 1] - y[i]) / step;
        res[i] -= (y[i + 2] - y[i]) / (2 * step);
    }
    res[num - 2] = -1;
    res[num - 1] = -1;
    return res;
}

double* SecondDifferential(double y[], int num, double step)
{
    double *res = new double[num];
    res[0] = -1;

    for (int i = 1; i < num - 1; i++) {
        res[i] = y[i - 1] - 2 * y[i] + y[i + 1];
        res[i] /= step * step;
    }
    res[num - 1] = -1;
    return res;
}
