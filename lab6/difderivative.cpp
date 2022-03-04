#include "difderivative.h"

double* LeftDifDerivative(double y[], int num, double step)
{
    double *res = new double[num];
    res[0] = 0;
    for (int i = 1; i < num; i++) {
        res[i] = (y[i] - y[i - 1]) / step;
    }
    return res;
}

double* RightDifDerivative(double y[], int num, double step)
{
    double *res = new double[num];
    for (int i = 0; i < num - 1; i++) {
        res[i] = (y[i + 1] - y[i]) / step;
    }
    y[num - 1] = -1;
    return res;
}

double* CentreDifDerivative(double y[], int num, double step)
{
    double *res = new double[num];
    res[0] = -1;
    for (int i = 1; i < num - 1; i++) {
        res[i] = (y[i + 1] - y[i - 1]) / (2 * step);
    }
    res[num - 1] = -1;
    return res;
}
