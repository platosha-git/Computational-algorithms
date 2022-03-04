#include "io_handler.h"
#include <stdlib.h>

void create_table_file(FILE *f, double ***table, double **p, int *num_points)
{
    fscanf(f, "%d", &(*num_points));
    (*table) = new double* [*num_points];
    for (int i = 0; i < *num_points; i++) {
        (*table)[i] = new double [2];
    }

    *p = new double [*num_points];

    for (int i = 0; i < *num_points; i++) {
        fscanf(f, "%lf", &(*table)[i][0]);
        fscanf(f, "%lf", &(*table)[i][1]);
        fscanf(f, "%lf", &(*p)[i]);
    }
}

void create_table_console(double ***table, double **p, int *num_points)
{
    printf("Input amount of points: ");
    scanf("%d", num_points);

    (*table) = new double* [*num_points];
    for (int i = 0; i < *num_points; i++) {
        (*table)[i] = new double [2];
    }

    *p = new double [*num_points];

    for (int i = 0; i < *num_points; i++) {
        printf("%d", i + 1);
        printf(" point\n\tx = ");
        scanf("%lf", &(*table)[i][0]);
        printf("\ty = ");
        scanf("%lf", &(*table)[i][1]);
        printf("\tWeight = ");
        scanf("%lf", &(*p)[i]);
    }
}

void change_table(double ***table, int *num_points)
{
    printf("Input point to change ( from 0 to %d)\n", *num_points);
    int i_ch = 0;
    scanf("%d", &i_ch);

    printf("Input x\n");
    scanf("%lf", &(*table)[i_ch][0]);
    printf("Input y\n");
    scanf("%lf", &(*table)[i_ch][1]);
}

void change_weight(double **p, int num_points)
{
    printf("Input num point to change weight\n");
    int i_ch = 0;
    scanf("%d", &i_ch);

    printf("Input weight\n");
    scanf("%lf", &(*p)[i_ch]);
}



void output_table(double **table, double *p, int num_points)
{
    printf("num = %d\n", num_points);
    for (int i = 0; i < num_points; i++) {
        printf("%.3lf   ", table[i][0]);
        printf("%.3lf   ", table[i][1]);
        printf("%.3lf   ", p[i]);
        printf("\n");
    }
}

void output_vector(double *v, int n)
{
    for (int i = 0; i < n; i++)
        printf("%.3f\n", v[i]);
}

void output_matr(double **matr, int s, int c)
{
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < c; j++) {
            printf("%.3lf ", matr[i][j]);
        }
        printf("\n");
    }
}
