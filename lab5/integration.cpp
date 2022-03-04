#include "integration.h"
#include <cmath>
#define pi 3.14

double Integrate(int n, int m, double t, int chin, int chex)
{
    double limits[2][2];
    limits[0][0] = 0; limits[0][1] = pi / 2;
    limits[1][0] = 0; limits[1][1] = pi / 2;

    double interval[2];
    interval[0] = n;
    interval[1] = m;

    double (*funcValue()) = BaseFunc(t);

    double resbtw = 0;
    if (chin == 1) {
        resbtw = IntegrateGauss(ArgsReduction(funcValue, x), limits[1][0], limits[1][1], interval[1]);
    }
    if (chin == 2) {
        resbtw = IntegrateSimpson(ArgsReduction(funcValue, x), limits[1][0], limits[1][1], interval[1]);
    }

    double res = 0;
    if (chex == 1) {
        res = IntegrateGauss(resbtw, limits[0][0], limits[0][1], interval[0]);
    }
    if (chex == 2) {
        res = IntegrateSimpson(resbtw, limits[0][0], limits[0][1], interval[0]);
    }
    return res;
}

double RecursFunction(double (*func(x, y)), double x)
{
    return func(x, y);
}
