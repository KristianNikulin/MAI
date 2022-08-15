#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct Points
{
    double x;
    double y; // y = f(x)
};

struct Result
{
    double y;
    int p;
};

double
realFunc(double x)
{
    double xexp = exp(x * x);
    return xexp;
}

double taylorFunc(double x, unsigned p)
{
    double s = 1;
    double ds = 1;
    for (unsigned i = 1; i < p; i++)
    {
        ds = ds * x * x / i;
        s = s + ds;
    }
    return s;
}

bool isClose(double a, double b)
{
    return fabs(a - b) < 1.0e-07;
}

struct Result makeCalculation(double x, double (*rFunc1)(double), double (*tFunc1)(double, unsigned))
{
    unsigned p = 1;
    double r = (*rFunc1)(x);
    double y = (*tFunc1)(x, p);
    // printf("x = %f    realFunc = %f    taylorFunc = %f    p = %i\n", x, r, y, p);
    while (!isClose(r, y))
    {
        y = (*tFunc1)(x, ++p);
        // printf("x = %f    realFunc = %f    taylorFunc = %f    p = %i\n", x, r, y, p);
    }
    struct Result res = {.y = y, .p = p};
    return res;
}

int main()
{
    double dd = 1e-7, f1, x, s, ds, x2, n = 0;
    double rf, tf, y;
    double a = 0.0, b = 1.0;
    unsigned pointsCount;
    pointsCount = 30;
    double step = (b - a) / pointsCount;
    struct Points *points;
    x = a;
    points = malloc((pointsCount += 1) * sizeof(struct Points));

    for (unsigned i = 0; i < pointsCount; i++, x += step)
    {
        points[i].x = x;
        struct Result res = makeCalculation(x, (*realFunc), (*taylorFunc));
        points[i].y = y;
        // printf("\npoints[x] = %f    points[y] = %f\n\n", points[i].x, points[i].y);
        printf("x = %f    realFunc = %f    taylorFunc = %f    p = %i\n", x, realFunc(x), res.y, res.p);
    }
    free(points);
    return 0;
}
