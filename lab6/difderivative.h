#ifndef DIFDERIVATIVE_H
#define DIFDERIVATIVE_H

double* LeftDifDerivative(double y[], int num, double step);
double* RightDifDerivative(double y[], int num, double step);
double* CentreDifDerivative(double y[], int num, double step);

#endif // DIFDERIVATIVE_H
