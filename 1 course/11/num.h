#include <stdio.h>
#include <stdbool.h>

enum Border
{
    New_number = 0,
    First_digit,
    Second_digit,
    Wrong_number
};

void searchDec(char a[], unsigned size, enum Border counter, char prelast, char last);

void print_Number(int number, bool positive);