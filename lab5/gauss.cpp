#include "gauss.h"

double IntegrateGauss(double (*func)(), double a, double b, double interval)
{
    double *A = nullptr;
    double *t = nullptr;
    Gauss(&A, &t);

    double res = 0;
    for (int i = 0; i < interval; i++) {
        res += (b - a) / 2 * A[i] * func(ArgToX(t[i], a, b));
    }
    return res;
}

double ArgToX(double a, double b, double t)
{
    double res = (b + a) / 2 + (b - a) * t / 2;
    return res;
}
