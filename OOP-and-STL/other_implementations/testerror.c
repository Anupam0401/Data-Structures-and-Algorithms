#include <stdio.h>

int main()
{
    int i, j;
    scanf("%d %d", &i, &j);
    for (;;)
    {
        if (i > 5)
            break;
        else
            j += 1;
        printf("%d ", j);
        i += j;
        return 0;
    }
    return 0;
}
