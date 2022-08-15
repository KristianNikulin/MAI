#include "sort.h"

// обмен местами двух элементов
void udtSwap(Udt *udt1, Udt *udt2)
{
    Udt tmp;

    tmp = *udt1;
    *udt1 = *udt2;
    *udt2 = tmp;
}

// сортировка линейным образом
void udtSelectionSort(Udt *udt)
{
    const int cap = udtCapacity(udt);
    Udt sorted, tmp;
    UDT_TYPE item;

    if (cap < 2)
        return;

    udtCreate(&sorted, cap);
    udtCreate(&tmp, cap);

    while (!udtEmpty(udt))
    {
        udtPushFront(&tmp, udtTopFront(udt)); // добавляем первый элемент udt в начало tmp
        udtPopFront(udt);                     // удаляем первый элемент udt

        //
        while (!udtEmpty(udt))
        {
            item = udtTopFront(udt); // берем значение первого элемента udt

            udtPopFront(udt); // удаляем элемент из начала udt

            if (item._key < udtTopFront(&tmp)._key) // если ключ первого элемента udt   <   ключа первого элемента tmp
                udtPushFront(&tmp, item);           // добавляем item в начало tmp
            else
                udtPushBack(&tmp, item); // иначе добавляем item в конец tmp
        }
        //

        udtPushBack(&sorted, udtTopFront(&tmp)); // берем значение первого элемента tmp и добавляем в конец sorted
        udtPopFront(&tmp);                       // удаляем элемент из начала tmp

        udtSwap(udt, &tmp); // обмен элементов между деками udt и tmp
    }

    udtSwap(udt, &sorted); // обмен элементов между деками udt и sorted

    udtDestroy(&sorted);
    udtDestroy(&tmp);
    printf("sorted\n");
}
