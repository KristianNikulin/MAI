#include "num.h"

void searchDec(char a[], unsigned size, enum Border counter, char prelast, char last)
{

    unsigned i = 0;
    char prev, preprev;
    if (counter != New_number)
    {
        prev = last;
        preprev = prelast;
    }
    bool positive = true;

    while (i < size && a[i] != 0)
    {

        if (i > 0)
        {
            prev = a[i - 1];
            if (i > 1)
                preprev = a[i - 2];
            else
                preprev = last;
        }

        if (a[i] >= '1' && a[i] <= '7' && counter == New_number)
        {
            counter = First_digit;
        }

        else if (a[i] >= '0' && a[i] <= '9' && counter == First_digit && prev <= '7' && !(prev == '7' && a[i] > '7'))
        {
            counter = Second_digit;
        }

        else if (a[i] == 10 || a[i] == '\f' || a[i] == ' ')
        {
            if (counter == Second_digit)
            {
                writeInt((preprev - 48) * 10 + prev - 48, positive);
            }
            counter = New_number;
            positive = true;
        }

        else if (!(counter == New_number && (a[i] == '-' || a[i] == '0') && !(prev == '-')))
        {
            counter = Wrong_number;
        }

        if (a[i] == '-')
        {
            positive = false;
        }
        i++;
    }
}

void print_Number(int number, bool positive)
{
    int first_digit = number / 10;

    int second_digit = number % 10;

    if (!positive)
        printf("moins "); // минус

    if (number >= 17 && number < 70) // и
    {
        switch (first_digit)
        {
        case 1:
            printf("dix"); // десять
            break;
        case 2:
            printf("vingt"); // двадцать
            break;
        case 3:
            printf("trente"); // тридцать
            break;
        case 4:
            printf("quarante"); // сорок
            break;
        case 5:
            printf("cinquante"); // пятьдесят
            break;
        case 6:
            printf("soixante"); // шестьдесят
            break;
        }
        switch (second_digit)
        {
        case 1:
            printf(" et un\n"); // один
            break;
        case 2:
            printf("-deux\n"); // два
            break;
        case 3:
            printf("-trois\n"); // три
            break;
        case 4:
            printf("-quatre\n"); // четыре
            break;
        case 5:
            printf("-cinq\n"); // пять
            break;
        case 6:
            printf("-six\n"); // шесть
            break;
        case 7:
            printf("-sept\n"); // семь
            break;
        case 8:
            printf("-huit\n"); // восемь
            break;
        case 9:
            printf("-neuf\n"); // девять
            break;
        default:
            printf("\n");
            break;
        }
    }

    else // a >= 70
    {
        printf("soixante");
        switch (second_digit)
        {
        case 0:
            printf("-dix\n"); // ноль
            break;
        case 1:
            printf(" et onze\n"); // один
            break;
        case 2:
            printf("-douze\n"); // два
            break;
        case 3:
            printf("-treize\n"); // три
            break;
        case 4:
            printf("-quatorze\n"); // четыре
            break;
        case 5:
            printf("-quinze\n"); // пять
            break;
        case 6:
            printf("-seize\n"); // шесть
            break;
        case 7:
            printf("-dix-sept\n"); // семь
            break;
        default:
            printf("\n");
            break;
        }
    }
}