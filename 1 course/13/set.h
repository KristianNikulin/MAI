#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t ByteType;
typedef uint16_t ElementType;

bool isOneByteEncoding(ByteType byte);

bool isTwoByteEncoding(ByteType byte);

bool isValidSecondByte(int valuefromstream);

ElementType Decode(ByteType firstbyte, ByteType secondbyte);

ElementType GetElementFromStream(FILE *file);

bool IsLetter(ElementType symbol); // буква?

bool IsVowel(ElementType value); // гласная?
