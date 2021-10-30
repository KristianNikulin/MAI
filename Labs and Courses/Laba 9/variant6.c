#include <stdio.h>
#include <stdlib.h>
//? ЛАБОРАТОРНАЯ РАБОТА № 9
//? ВАРИАНТ 6

// ТОЧКА
struct Point
{
    int i;
    int j;
    int l; // начальные значения из лабы
};

// MAX
int maxx(int x, int y)
{
    return (x > y) ? x : y; // тернарный оператор
}

// MIN
int minx(int x, int y)
{
    return (x < y) ? x : y;
}

// ОПРЕДЕЛЕНИЕ ЗНАЧЕНИЯ ЗНАКА ПЕРЕМЕННОЙ
int sign(int w)
{
    if (w == 0)
    {
        return w;
    }
    else
    {
        return (w > 0) ? 1 : -1;
    }
}

// ПРОВЕРКА РАСПОЛОЖЕНИЯ ТОЧКИ
int in_square(struct Point p)
{
    int x1 = 5;
    int y1 = -5; // Левая верхняя точка квадрата

    int x4 = 15;
    int y4 = -15; // Правая нижняя точка квадрат

    return (p.i >= x1 && p.i <= x4) && (p.j <= y1 && p.j >= y4);
}

// ИЗМЕНЕНИЕ КООРДИНАТЫ i
int change_i(int i, int j, int l, int k)
{
    return minx(l % 5, i * k % 5) + j + k / 3;
}

// ИЗМЕНЕНИЕ КООРДИНАТЫ j
int change_j(int i, int j, int l, int k)
{
    return maxx(-3 * i, 2 * j) / 5 - abs(j - l);
}

// ИЗМЕНЕНИЕ ПАРАМЕТРА l
int change_l(int i, int j, int l, int k)
{
    return j + l % 7 + k * sign(i) % 10;
}

struct Point change(struct Point p, int k)
{
    struct Point new_point;

    new_point.i = change_i(p.i, p.j, p.l, k);

    new_point.j = change_j(p.i, p.j, p.l, k);

    new_point.l = change_l(p.i, p.j, p.l, k);

    return new_point;
}

// MAIN
int main()
{
    unsigned k = 1; // кол-во шагов

    struct Point point = {.i = 22, .j = 10, .l = 10};

    while (!in_square(point) && k <= 50) // Проверка
    {
        point = change(point, k);
        k++;
    }

    if (k < 51)
    {
        printf("\nINSIDE\n"); // Внутри
    }
    else
    {
        printf("\nOUTSIDE\n"); // Снаружи
    }

    printf("\n%d %d\n", point.i, point.j); // Координаты
    printf("\n%d %d\n", k, point.l);       // Шаг и параметр движения

    return 0;
}
// INSIDE
// 6 -11
// 28 2

// INSIDE
// 7 -7
// 34 -10
