#include <stdio.h>
#include "sort.h"

// ДЕК - ПОИСК И УДАЛЕНИЕ МАКСИМАЛЬНОГО ЭЛЕМЕНТА - СОРТИРОВКА ЛИНЕЙНЫМ ОБРАЗОМ

void getLine(char *str, const int size)
{
    int cnt = 0, ch;

    while ((ch = getchar()) != '\n' && cnt < size - 1)
        str[cnt++] = ch;

    str[cnt] = '\0';
}

void print_help()
{
    printf("\n1) Добавить элемент слева\n");
    printf("2) Добавить элемент справа\n");
    printf("3) Удалить элемент слева\n");
    printf("4) Удалить элемент справа\n");
    printf("5) Размер дека\n");
    printf("6) Сортировка\n");
    printf("7) Поиск и удаление строки максимальной длины\n");
    printf("8) Печать\n");
    printf("9) Выход\n\n");
}

int main(void)
{
    system("chcp 1251 > nul");
    print_help();

    const int N = 10; // общий размер дека

    int action;
    char tmpCh;
    Udt udt;
    Item item;
    udtCreate(&udt, N);
    char c;

    while ((c = getchar()) != EOF)
    {

        if (c == '\n')
            continue;

        switch (c)
        {
        case '1':
        {
            printf("Введите ключ (только числа): ");
            if (scanf("%d", &item._key))
            {
                scanf("%c", &tmpCh);
                printf("Введите Строку: ");
                getLine(item._str, sizeof(item._str));

                if (udtPushFront(&udt, item))
                    printf("\nЭлемент с ключом %d и строкой '%s' добавлен\n", item._key, item._str);
                else
                    printf("Дек полон\n");

                print_help();
                break;
            }
            else
            {
                printf("\nerror\n");
                print_help();
                break;
            }
        }

        case '2':
        {
            printf("Введите ключ (только числа): ");
            if (scanf("%d", &item._key))
            {
                scanf("%c", &tmpCh);
                printf("Введите Строку: ");
                getLine(item._str, sizeof(item._str));

                if (udtPushBack(&udt, item))
                    printf("\nЭлемент с ключом %d и строкой '%s' добавлен\n", item._key, item._str);
                else
                    printf("Дек полон\n");

                print_help();
                break;
            }
            else
            {
                printf("\nerror\n");
                print_help();
                break;
            }
        }

        case '3':
        {
            if (udtSize(&udt) > 0)
            {
                item = udtTopFront(&udt);

                udtPopFront(&udt);

                printf("\nЭлемент с ключом %d и строкой '%s' удален\n", item._key, item._str);
            }
            else
                printf("Дек пуст\n");
            print_help();
            break;
        }

        case '4':
        {
            if (udtSize(&udt) > 0)
            {
                item = udtTopBack(&udt);

                udtPopBack(&udt);

                printf("\nЭлемент с ключом %d и строкой '%s' удален\n", item._key, item._str);
            }
            else
                printf("Дек пуст\n");
            print_help();
            break;
        }

        case '5':
        {
            printf("Размер дека: %d (Общий размер: %d)\n", udtSize(&udt), N);
            print_help();
            break;
        }

        case '6':
        {
            udtSelectionSort(&udt);
            print_help();
            break;
        }

        case '7':
        {
            task(&udt);
            print_help();
            break;
        }

        case '8':
        {
            if (udtSize(&udt) > 0)
            {
                printf("\nДек:\n");

                udtPrint(&udt);
            }
            else
                printf("\nДек пуст\n");
            print_help();
            break;
        }
        case '9':
            return 0;

        default:
        {
            break;
        }
        }
    }
    udtDestroy(&udt);
    return 0;
}
