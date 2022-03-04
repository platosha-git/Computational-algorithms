#ifndef GAUSS_H
#define GAUSS_H

#include "basefunc.h"

double IntegrateGauss(double funcValue, double a, double b, double interval);
double ArgToX(double a, double b, double t);
double Gauss(double **A, double **t);

#endif // GAUSS_H
