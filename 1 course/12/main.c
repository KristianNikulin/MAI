#include "num.h"
/*
ВАРИАНТ 26
ПОСЛЕ КАЖДЫХ ДВУХ ЦИФР ВСТАВЛЯТЬ ИХ СУММУ
*/

int main()
{
    int a;
    scanf("%d", &a);

    struct Number n = makeNumberFromInt(a);

    print_Number_with_sums(n);

    return 0;
}