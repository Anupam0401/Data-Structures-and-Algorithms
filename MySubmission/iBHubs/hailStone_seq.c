#include <stdio.h>

int get_hailstone_term(int n);

void print_hailstone_sequence(int n);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        print_hailstone_sequence(n);
        printf("\n\n\n");
    }

    return 0;
}

void print_hailstone_sequence(int n)
{
    printf("%d ", n);
    if (n == 1)
        return;

    if (n % 2 == 0)
        return print_hailstone_sequence(n / 2);
    else
        return print_hailstone_sequence(3 * n + 1);
}