#include<stdio.h>
int main()
{
    long long int m,n;
    scanf("%lld%lld",&m,&n);
    long long int a[m][n];
    for(long long int i=0;i<m;i++)
    {
        for(long long int j=0;j<n;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    long long int direction=0,row_min=0,row_max=m-1,col_min=0,col_max=n-1;
    long long int result[m*n];
    long long int c=0,i;
    while (row_min <= row_max && col_min <= col_max)
    {
        switch (direction)
        {

        case 0:
        {
            for (i = row_max; i >=row_min; i--)
            {
                result[c++] = a[i][col_max];
            }
            col_max--;
            direction++;
            break;
        }
        case 1:
        {
            for (i = col_max; i >=col_min; i--)
            {
                result[c++] = a[row_min][i];
            }
            row_min++;
            direction++;
            break;
        }
        case 2: // Right to left
        {
            for (i = row_min; i<=row_max; i++)
            {
                result[c++] = a[i][col_min];
            }
            col_min++;
            direction++;
            break;
        }
        case 3:
        {
            for (i = col_min; i <=col_max; i++)
            {
                result[c++] = a[row_max][i];
            }
            row_max--;
            direction=0;
            break;
        }
        }
    }
    for(long long int k=0;k<m*n;k++)
    {
        printf("%lld ",result[k]);
    }
    return 0;
}
