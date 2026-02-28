
#include <stdio.h>
#include <math.h>
#include <inttypes.h>


//максимальное количество итераций при вычислениях
#define NUMBER_MAX_ITERATION 1500



double f1(double x);

double f2(double x);

double f3(double x);

double f4(double x);

double f5(double x);

//поиск решения методом деления отрезка пополам
double root(double (*f)(double), double (*g)(double), double a, double b, double eps, unsigned int * count_iteration) ;


// вычисление интеграла методом трапеций от функции f(x) на интервале 
//[a,b] с точностью eps
double integral(double (*f)(double), double a, double b, double eps, unsigned int * count_iteration);

//функция для вывода справки(помощи) о ключах командной строки 
void print_help(void);



