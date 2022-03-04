#include "rmsApproximation.h"

double fpow(double arg, double p)
{
    double res = 1;
    for (int i = 0; i < p; i++) {
        res *= arg;
    }
    return res;
}

double *squaring(double **table, double *p, int num_points, int degree)
{
    //(x^k, x^m) = sum(pi * xi^(k+m)
    double *x_scolar = new double [2 * degree + 1];
    for (int i = 0; i < 2 * degree + 1; i++) {
        for (int j = 0; j < num_points; j++) {
            x_scolar[i] += p[j] * fpow(table[j][0], i);
        }
    }

    //(y, x^k) = sum(pi * yi * xi^k)
    double *yx_scolar = new double [degree + 1];
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j < num_points; j++) {
            yx_scolar[i] += p[j] * table[j][1] * fpow(table[j][0], i);
        }
    }

    //Построение матрицы коэффициентов
    double **res_table = new double* [degree + 1];
    for (int i = 0; i <= degree; i++) {
        res_table[i] = new double [degree + 2];
    }

    for (int j = 0; j < degree + 2; j++) {
        for (int i = 0; i < degree + 1; i++) {
            res_table[i][j] = x_scolar[i + j];
        }
    }
    for (int i = 0; i < degree + 1; i++) {
        res_table[i][degree + 1] = yx_scolar[i];
    }

    //Гаус, приведение к ступенчатому виду
    for (int k = 0; k <= degree; k++) {
        for (int i = k + 1; i <= degree; i++) {
            double kf = res_table[i][k]/res_table[k][k];
            for (int j = k; j <= degree + 1; j++) {
                res_table[i][j] -= kf * res_table[k][j];
            }
        }
    }

    //Нахождение коэффициентов ak
    double *a = new double [degree];
    for (int i = degree; i >= 0; i--) {
        for (int j = degree; j > i; j--) {
            res_table[i][degree + 1] -= a[j] * res_table[i][j];
        }
        a[i] = res_table[i][degree + 1] / res_table[i][i];
    }

    for (int i = 0; i < degree + 1; i++) {
        delete [] res_table[i];
    }

    delete [] res_table;
    delete [] yx_scolar;
    delete [] x_scolar;

    return a;
}


