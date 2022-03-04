#include "simpson.h"
#include <iostream>
using namespace std;

double IntegrateSimpson(double (*func()), double a, double b, double interval)
{
    if (interval < 3) {
        cout << "The interval is incorrect\n";
        return -1;
    }

    double step = (b - a) / (interval - 1);
    double x = a;
    double res = 0;

    for (int i = 0; i < (interval - 1) / 2; i++) {
        res += func(x) + 4 * func(x + step) + func(x + 2 * step);
        x += 2 * step;
    }

    return res * (step / 3);
}


