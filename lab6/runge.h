#ifndef RUNGE_H
#define RUNGE_H

double* LeftRunge(double y[], int num, double step);
double* RightRunge(double y[], int num, double step);

double* SecondDifferential(double y[], int num, double step);

#endif // RUNGE_H
