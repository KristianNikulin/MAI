#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double func(double x)
{
    double ff, f1, f2;
    f1 = sqrt(1 - x);
    f2 = tan(x);
    ff = f1 - f2;
    return ff;
}

double calculation(double a, double b, double (*fun)(double))
{
    double ak, bk, ak1, bk1, xk, xabk;
    double fak, fabk, fbk;
    double dd = 1.0e-5;
    int k = 1;
    ak = a;
    bk = b;
    fak = (*fun)(ak);
    fbk = (*fun)(bk);
    printf("\nak = %f    bk = %f    fak = %f    fbk = %f\n\n", ak, bk, fak, fbk);

    if ((fak * fbk) < 0)
    {
        while (fabs(ak - bk) > 1.0e-6) //!!!
        {
            fak = (*fun)(ak);
            fbk = (*fun)(bk);
            xabk = (ak + bk) / 2;
            fabk = (*fun)(xabk);

            if ((fak * fabk) < 0) // значение функций слева разного знака - от a до средней
            {
                bk1 = xabk;
                ak1 = ak;
                ak = ak1;
                ;
                bk = bk1;
                k = k + 1;
                printf("sleva    ak1 = %f    bk1 = %f    k = %i    fak = %f    fabk = %f\n\n", ak1, bk1, k, fak, fabk);
            }

            if ((fbk * fabk) < 0) // значение функций справа разного знака - от средней до b
            {
                ak1 = xabk;
                bk1 = bk;
                ak = ak1;
                bk = bk1;
                k = k + 1;
                printf("sprava   ak1 = %f    bk1 = %f    k = %i    fbk = %f    fabk = %f\n\n", ak1, bk1, k, fbk, fabk);
            }
        }

        xk = (ak + bk) / 2;
        return xk;
    }
    printf("error\n");
    return 0;
}

int main()
{
    double x0 = 0, xn = 1, xx, xf;
    xx = calculation(x0, xn, (*func));
    xf = func(xx);
    printf("xx = %f    xf = %f\n", xx, xf);
    return 0;
}
