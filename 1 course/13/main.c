#include "set.h"

enum State
{
    Separator,
    FirstLetter,
    Wrong
};

int main()
{
    FILE *txt = fopen("input.txt", "r");

    enum State element;

    ElementType value = 1;

    ElementType value_prev = 1;

    bool InTheMiddle = false;

    while (value != 0)
    {
        value_prev = value;

        value = GetElementFromStream(txt);

        if (IsLetter(value))
        {
            if (!InTheMiddle)
            {
                if (IsVowel(value))
                {
                    element = FirstLetter;
                    InTheMiddle = true;
                }

                else
                {
                    element = Wrong;
                    InTheMiddle = true;
                }
            }

            else
            {
                continue;
            }
        }

        else // SEPARATOR
        {

            if ((IsVowel(value_prev)) && (element = FirstLetter))
            {
                printf("YES ");
                return 0;
            }

            else
            {
                InTheMiddle = false;
                continue;
            }
        }
    }

    fclose(txt);
    return 0;
}
