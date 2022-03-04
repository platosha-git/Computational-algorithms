#include "alignment.h"

double* LeftAlignment(double x[], double y[], int num)
{
    double *res = new double[num];
    res[0] = -1;
    res[1] = -1;
    for (int i = 1; i < num; i++) {
        res[i + 1] = 1 / y[i] - 1 / y[i - 1];
        res[i + 1] /= 1 / x[i] - 1 / x[i - 1];
        res[i + 1] *= (y[i - 1] * y[i - 1]) / (x[i - 1] * x[i - 1]);
    }
    return res;
}

double* RightAlignment(double x[], double y[], int num)
{
    double *res = new double[num];
    for (int i = 0; i < num - 2; i++) {
        res[i] = 1 / y[i+1] - 1 / y[i];
        res[i] /= 1 / x[i+1] - 1 / x[i];
        res[i] *= (y[i] * y[i]) / (x[i] * x[i]);
    }
    res[num - 2] = -1;
    res[num - 1] = -1;
    return res;
}
