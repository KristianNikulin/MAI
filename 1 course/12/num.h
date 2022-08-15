#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Number
{
    unsigned char digits[100];
    unsigned int size;

    bool positive;
};

struct Number makeNumberFromInt(int number);
void print_Number_with_sums(struct Number n);

// Не используются
unsigned char getDigit(struct Number n, unsigned position);
struct Number setDigit(struct Number n, unsigned char value, unsigned position);
int makeIntFromNumber(struct Number n);
struct Number clear(struct Number n);