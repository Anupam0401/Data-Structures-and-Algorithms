#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;

// Neil has a perfect binary tree with N nodes, and an integer M. He can assign values to nodes. He calls the tree good if the following conditions are met:

// Nodes' values are positive integers no more than M.
// Nodes at even levels have values strictly more than their parents' values.
// Nodes at odd levels have values strictly less than their parents's values.
// How many ways can Neil assign values to all nodes to get a good perfect binary tree? Since the answer can be large, please output it under modulo 10^9+7.

// Note:

// The root of the tree is at layer 1.
// Two assignments are different if there is at least one node with different values in both assignments.
// You may need to use 64-bit data types in your programming language to take input.

// INPUT: n is the number of nodes on the tree and m is the maximum value of any node.
// output on a single line the number of different assignment modulo 10^9+7.

void solve(lli n, lli m)
{
    lli ans = 0;
    lli mod = 1000000007;
    lli dp[n + 1][m + 1];
    for (lli i = 0; i <= n; i++)
    {
        for (lli j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= m; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
        }
    }
    ans = dp[n][m];
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        lli n, m;
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}
