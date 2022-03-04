#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <iostream>
using namespace std;
#include "gauss.h"
#include "simpson.h"

double Integrate(int n, int m, double t, int chin, int chex);
double ArgsReduction(double* func, double y);

#endif // INTEGRATION_H
