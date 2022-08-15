#include "set.h"

bool isOneByteEncoding(ByteType byte)
{
    return (byte & 128) == 0;
}

bool isTwoByteEncoding(ByteType byte)
{
    return (byte >> 5) == 6;
}

bool isValidSecondByte(int valuefromstream)
{
    return (valuefromstream >> 6) == 2;
}

ElementType Decode(ByteType firstbyte, ByteType secondbyte)
{
    return (firstbyte << 8) | secondbyte;
}

ElementType GetElementFromStream(FILE *file)
{
    int valuefromstream = fgetc(file);

    if (valuefromstream == EOF)
        return 0;

    ByteType firstbyte = (ByteType)valuefromstream;

    if (!isOneByteEncoding(firstbyte))
    {
        return firstbyte;
    }
    else if (!isTwoByteEncoding(firstbyte))
    {
        valuefromstream = fgetc(file);

        if (isValidSecondByte(valuefromstream))
        {
            return 0;
        }

        ByteType secondbyte = (ByteType)valuefromstream;

        return Decode(firstbyte, secondbyte);
    }
    else
    {
        return 0;
    }
}

bool IsLetter(ElementType valuefromstream) // Юникод кодировки
{

    if (valuefromstream >= 65 && valuefromstream <= 90)
    {
        //Big english letters

        return true;
    }
    else if (valuefromstream >= 97 && valuefromstream <= 122)
    {
        //Small english letters

        return true;
    }

    else if ((valuefromstream >= 1040 && valuefromstream <= 1071) || (valuefromstream == 1025))
    {
        // А - Я , Ё
        //Big russian letters

        return true;
    }

    else if ((valuefromstream >= 1072 && valuefromstream <= 1103) || (valuefromstream == 1105)) //а - п , р - я , ё
    {
        // Small russian letters

        return true;
    }

    else
    {
        return false;
    }
}

bool IsVowel(ElementType value) // Юникод кодировки
{
    if (value == 65 || value == 69 || value == 73 || value == 85 || value == 89 || value == 79)
    {
        return true;
        //AEIUYO
    }
    else if (value == 97 || value == 101 || value == 105 || value == 117 || value == 121 || value == 111)
    {
        return true;
        //aeiuyo
    }
    else if (value == 1040 || value == 1045 || value == 1025 || value == 1048 || value == 1054 || value == 1059 || value == 1067 || value == 1069 || value == 1070 || value == 1071)
    {
        return true;
        //АЕЁИОУЫЭЮЯ
    }
    else if (value == 1072 || value == 1077 || value == 1105 || value == 1080 || value == 1086 || value == 1091 || value == 1099 || value == 1101 || value == 1102 || value == 1103)
    {
        return true;
        //аеёиоуыэюя
    }
    else
    {
        return false;
    }
}
//int A;