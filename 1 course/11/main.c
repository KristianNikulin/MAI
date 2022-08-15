#include "num.h"

#define SIZE 100

int main()
{

    char buffer[SIZE];
    enum Border border;
    char prelast, last;

    while (fgets(buffer, SIZE, stdin))
    {
        border = New_number;
        prelast = 48;
        last = 48;

        searchDec(buffer, SIZE, border, prelast, last);

        prelast = buffer[SIZE - 2];
        last = buffer[SIZE - 1];

        if (last == 9 || last == 10 || last == 32)
            border == New_number;
        else if ((prelast == 10 || prelast == 32) && (last <= '7' && last >= '1'))
            border = First_digit;
        else if ((buffer[SIZE - 3] == 10 || buffer[SIZE - 3] == 32) && (prelast <= '7' && prelast >= '1') && (last >= '0' && last <= '9') && !(last > '7' && prelast == '7'))
            border = Second_digit;
        else
            border = Wrong_number;
    }
    return 0;
}