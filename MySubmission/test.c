// Nasir and two of his henchmen are planning to attack N shops of the Qureshi clan. The shops are conveniently lined up, and numbered from 1 to N. The i-th shop contains Ai kg of coal.

// For a given subarray of shops [AL,AL+1,…,AR], the bitwise and of this subarray is defined to be the bitwise AND of the coal contained in each of the shops, i.e, AL&AL+1&…&AR.

// The damage caused when bombing the i-th shop is computed to be the maximum bitwise and over all subarrays containing shop i, and whose size is strictly larger than 1.

// For each shop (1≤i≤N), find the damage caused when Nasir bombs it.

// Input Format
// The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N, denoting the number of shops.
// The second line of each test case contains N space-separated integers, the i-th of which is Ai, representing the amount of coal in the i-th shop.
// Output Format
// For each test case, print a single line containing N integers d1,d2,…,dn where di represents the maximum damage that can be caused if the i-th shop is to be bombed.

#include <stdio.h>
int main()
{
    int T, N, i, j;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        int A[N];
        for (i = 0; i < N; i++)
            scanf("%d", &A[i]);
        int dp[N][N];
        for (i = 0; i < N; i++)
            dp[i][i] = A[i];
        for (i = 0; i < N; i++)
            for (j = i + 1; j < N; j++)
                dp[i][j] = A[i] & A[j];
        for (i = 0; i < N; i++)
            for (j = i + 1; j < N; j++)
                for (int k = j + 1; k < N; k++)
                    dp[i][j] = dp[i][j] & dp[j][k];
        for (i = 0; i < N; i++)
            printf("%d ", dp[0][i]);
        printf("\n");
    }
}