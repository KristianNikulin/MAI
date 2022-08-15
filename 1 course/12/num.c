#include "num.h"
#include <math.h>

struct Number makeNumberFromInt(int number)
{
    struct Number n = {.digits = {0}, .size = 0};

    n.positive = number >= 0 ? true : false;

    if (abs(number) < 10) // Проверка! Должно быть минимум 2 цифры в числе
    {
        return n;
    }

    number = abs(number);
    while (number > 0)
    {
        n.digits[n.size] = number % 10;
        n.size++;
        number /= 10;
    }

    return n;
};

void print_Number_with_sums(struct Number n)
{
    long long CurrentDigit = n.size - 1;

    if (n.size < 2) // Проверка
    {
        printf("ERROR. Only one digit!");
        n.positive = true;
        CurrentDigit = -1;
    }

    if (!n.positive)
    {
        printf("-");
    }

    int summ = 0;
    int count = 0;

    while (CurrentDigit >= 0)
    {

        summ += n.digits[CurrentDigit];
        count++;
        printf("%u", n.digits[CurrentDigit--]);
        if (count % 2 == 0)
        {
            printf("%d", summ);
            summ = 0;
        }
    }
    printf("\n");
};

//
//
//
//
//

unsigned char getDigit(struct Number n, unsigned position)
{
    return n.digits[position];
}

struct Number setDigit(struct Number n, unsigned char value, unsigned position)
{
    n.digits[position] = value;
};

int makeIntFromNumber(struct Number n)
{
    int number = 0;
    int digit = 0;

    while (digit < n.size)
    {
        number += pow(10, digit) * n.digits[digit];
        digit++;
    }

    if (!n.positive)
    {
        number *= -1;
    }

    return number;
}

struct Number clear(struct Number n)
{
    while (n.size != 0)
    {
        n.digits[n.size--] = 0;
    }
    n.positive = true;

    return n;
};