#include <stdio.h>
#include <stdlib.h>

#define size 3

int main()
{
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    int matrix[size + 1][size + 1];

    // ЗАПОЛНЕНИЕ МАТРИЦЫ
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fscanf(in, "%d", &matrix[i][j]);
        }
    }

    // ОБМЕН МЕСТАМИ ГЛАВНОЙ И ПОБОЧНОЙ ДИАГОНАЛЕЙ
    for (int i = 0; i < size; i++)
    {
        int z = matrix[i][i];
        matrix[i][i] = matrix[i][size - i - 1];
        matrix[i][size - i - 1] = z;
    }

    // ВЫВОД В ФАЙЛ
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fprintf(out, "%d ", matrix[i][j]); // строка, столбец
            printf("%d ", matrix[i][j]);
        }
        fprintf(out, "\n");
        printf("\n");
    }

    fclose(in);
    fclose(out);
    return 0;
}
