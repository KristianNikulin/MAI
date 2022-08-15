#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double func(double x)
{
    double ff = 3 * x - 14 + exp(x) - exp(-x);
    return ff;
}

double func1(double x) // первая производная
{
    double ff1 = 3 + exp(x) + exp(-x);
    return ff1;
}

double func11(double x) // вторая производная
{
    double ff11 = exp(x) - exp(-x);
    return ff11;
}

double calculation(double a, double b, double (*fun)(double), double (*fun1)(double x), double (*fun11)(double))
{
    double x, x1;
    double ff;
    double dd = 1.0e-5;
    int k = 1;
    x = (a + b) / 2;
    double fx = (*fun)(x);
    double fx1 = (*fun1)(x);
    fx1 = fx1 * fx1;
    double fx11 = (*fun11)(x);
    printf("x = %f    fx = %f    fx1 = %f    fx11 = %f\n", x, fx, fx1, fx11);

    if (fabs((fx) * (fx11)) < (fx1) * (fx1))
    {
        printf("\nrequirement [fx(x)*fx11(x)]<[fx1(x)**2] is realized\n\n");
        while (fabs(x - x1) > dd)
        {
            x = x1;
            ff = (*fun)(x);
            x1 = x - ((ff)) / ((*fun1)(x));
            printf("x = %f    k = %i    ff = %f\n", x, k, ff);
            k++;
        }
        return x1;
    }

    printf("error interval of argument");
    return 0;
}

int main()
{
    double x0 = 1, xn = 3, xx, xf;
    printf("\n");
    xx = calculation(x0, xn, (*func), (*func1), (*func11));
    xf = func(xx);
    printf("\nxx = %f    xf = %f\n", xx, xf);

    return 0;
}
