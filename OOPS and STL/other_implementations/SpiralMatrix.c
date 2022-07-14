#include <stdio.h>

int main()
{
    long long int size;
    scanf("%lld", &size);
    long long int result[size][size];

    long long int direction = 0, i, j, elem_value = 1, row_min = 0, row_max = size - 1, col_min = 0, col_max = size - 1;

    while (row_min <= row_max && col_min <= col_max)
    {
        switch (direction)
        {

        case 0: // left to right.
        {
            for (i = col_min; i <= col_max; i++)
            {
                result[row_min][i] = elem_value;
                elem_value++;
            }
            row_min++;
            direction++;
            break;
        }
        case 1: // Top to Bottom
        {
            for (i = row_min; i <= row_max; i++)
            {
                result[i][col_max] = elem_value;
                elem_value++;
            }
            col_max--;
            direction++;
            break;
        }
        case 2: // Right to left
        {
            for (i = col_max; i >= col_min; i--)
            {
                result[row_max][i] = elem_value;
                elem_value++;
            }
            row_max--;
            direction++;
            break;
        }
        case 3: // Bottom to Top
        {
            for (i = row_max; i >= row_min; i--)
            {
                result[i][col_min] = elem_value;
                elem_value++;
            }
            col_min++;
            direction = 0;
            break;
        }
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (j == size - 1)
            {
                printf("%lld", result[i][j]);
            }
            else
            {
                printf("%lld ", result[i][j]);
            }
        }
        if (i != (size - 1))
        {
            printf("\n");
        }
    }
    return 0;
}
