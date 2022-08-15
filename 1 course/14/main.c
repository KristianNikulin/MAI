#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define size 7

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

    int i1, i0, j0, di, dj, ii, jj, i, j, k1;
    k1 = size - 1;
    i0 = 0;
    j0 = 0;
    di = 1;
    dj = 1;

    for (i = i0; i <= k1; i = i + di)
    {
        ii = i;
        for (j = j0; j <= i; j = j + dj)
        {
            fprintf(out, "%i ", matrix[ii][j]);
            ii = ii - 1;
        }
    }

    j = j - k1;
    for (; j <= k1; j = j + dj)
    {
        jj = j;
        for (i = k1; i >= j; i = i - di)
        {
            fprintf(out, "%i ", matrix[i][jj]);
            jj = jj + 1;
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}
