#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

double func(double x)
{
    double ff = 1 - x + sin(x) - log(1 + x);
    return ff;
}

double funcx(double x) // x = f(x)
{
    double ff = 1 + sin(x) - log(1 + x);
    return ff;
}

double func1x(double x) // производная
{
    double ff1 = cos(x) - 1 / x;
    return ff1;
}

bool isclose(double a, double b)
{
    return fabs(a - b) < 1.0e-5;
}

bool funcpoints(double a, double b, double (*fun1)(double))
{
    while (!isclose(a, b))
    {
        if (fabs(fun1(a)) >= 1)
        {
            return false;
        }
        a += 0.01;
    }
    return true;
}

double calculation(double a, double b, double (*fun)(double), double (*fun1)(double))
{
    double x, x1, xk, xk1;
    double ff;
    double dd;
    int k = 1;
    xk = (a + b) / 2;
    xk1 = b;
    dd = xk - xk1;
    double fx1 = (*fun1)(xk);

    if (funcpoints(a, b, (*fun1)))
    {
        printf("\nrequirement  [fx1x(x)] < 1  is realized\n\n"); // fx1 = %f, fx1
        printf("xk = %f     k = %i    xk1 = %f\n\n", xk, k, xk1);

        while (fabs(dd) > 1.0e-5)
        {
            xk1 = (*fun)(xk);
            dd = xk - xk1;
            k++;
            xk = xk1;
            printf("xk1 = %f    k = %i\n\n", xk1, k);
        }
        return xk1;
    }
    printf("error\n");
    return 0;
}

int main()
{
    double x0 = 1, xn = 1.5, xx, xf;
    xx = calculation(x0, xn, (*funcx), (*func1x));
    xf = func(xx);
    printf("xx = %f    xf = %f\n", xx, xf);
    return 0;
}
