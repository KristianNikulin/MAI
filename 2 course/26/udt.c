#include "udt.h"

// создать дек
void udtCreate(Udt *udt, const int capacity)
{
    int i;
    UDT_TYPE item;

    item._key = 0;
    item._str[0] = '\0';

    if (capacity <= 0)
        return;

    udt->_data = (UDT_TYPE *)malloc(sizeof(UDT_TYPE) * capacity);

    for (i = 0; i < capacity; i++)
        udt->_data[i] = item;

    udt->_capacity = capacity;
    udt->_size = 0;
    udt->_first = (capacity == 1 ? 0 : 1);
    udt->_last = 0;
}

//добавить элемент в начало
int udtPushFront(Udt *udt, const UDT_TYPE value)
{
    const int pos = (udt->_first + udt->_capacity - 1) % udt->_capacity;

    if (udt->_size == udt->_capacity)
        return 0;

    udt->_data[pos] = value;
    udt->_first = pos;
    udt->_size++;

    return 1;
}

// добавить элемент в конец
int udtPushBack(Udt *udt, const UDT_TYPE value)
{
    const int pos = (udt->_last + udt->_capacity + 1) % udt->_capacity;

    if (udt->_size == udt->_capacity)
        return 0;

    udt->_data[pos] = value;
    udt->_last = pos;
    udt->_size++;

    return 1;
}

// удалить элемент из начала
void udtPopFront(Udt *udt)
{
    const int pos = (udt->_first + udt->_capacity + 1) % udt->_capacity;
    UDT_TYPE item;

    item._key = 0;
    item._str[0] = '\0';

    if (udt->_size == 0)
        return;

    udt->_data[udt->_first] = item;
    udt->_first = pos;
    udt->_size--;
}

// удалить элемент из конца
void udtPopBack(Udt *udt)
{
    const int pos = (udt->_last + udt->_capacity - 1) % udt->_capacity;
    UDT_TYPE item;

    item._key = 0;
    item._str[0] = '\0';

    if (udt->_size == 0)
        return;

    udt->_data[udt->_last] = item;
    udt->_last = pos;
    udt->_size--;
}

// значение первого элемента
UDT_TYPE udtTopFront(const Udt *udt)
{
    return udt->_data[udt->_first];
}

// значение последнего элемента
UDT_TYPE udtTopBack(const Udt *udt)
{
    return udt->_data[udt->_last];
}

// количество элементов в деке
int udtSize(const Udt *udt)
{
    return udt->_size;
}

// размер дека
int udtCapacity(const Udt *udt)
{
    return udt->_capacity;
}

int udtEmpty(const Udt *udt)
{
    return udt->_size == 0;
}

// распечатать дек
void udtPrint(Udt *udt)
{
    int i;
    Item item;

    printf("+--------+-----------+------------------------------+\n");
    printf("| Number |    Key    |            String            |\n");
    printf("+--------+-----------+------------------------------+\n");

    for (i = 0; i < udtSize(udt); i++)
    {
        item = udt->_data[(i + udt->_first) % udt->_capacity];

        printf("|%8d|%11d|%30s|\n", i + 1, item._key, item._str);
    }
    printf("+--------+-----------+------------------------------+\n");
}

// удалить дек
void udtDestroy(Udt *udt)
{
    if (udt->_data != NULL)
    {
        free(udt->_data);

        udt->_data = NULL;
    }
    udt->_capacity = 0;
    udt->_size = 0;
    udt->_first = 0;
    udt->_last = 0;
}

// поиск и удаление максимального элемента
void task(Udt *udt)
{
    if (!udt || !udt->_data)
        return;

    int max = 0;
    int i = 0;
    Item item, max_item, buffer;

    for (int j = 0; j < udtSize(udt); j++)
    {

        item = udt->_data[(j + udt->_first) % udt->_capacity];
        // printf("\n%s\n", item._str);
        // printf("\n%d\n", strlen(item._str));

        if (strlen(item._str) > max)
        {
            max = strlen(item._str);
            max_item = item;
            i = j;
        }
        // printf("\n%s\n", max_item._str);
        // printf("\ni = %d\n", i);
    }

    for (i; i < udtSize(udt) - 1; i++)
    {
        buffer = udt->_data[(i + udt->_first + 1) % udt->_capacity];
        udt->_data[(i + udt->_first + 1) % udt->_capacity] = udt->_data[(i + udt->_first) % udt->_capacity];
        udt->_data[(i + udt->_first) % udt->_capacity] = buffer;
    }
    udtPopBack(udt);
    printf("deleted\n");
}
