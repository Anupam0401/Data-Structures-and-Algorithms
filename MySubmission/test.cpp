// there is a rectangular forest with a total of m*n trees planted, with a total of 3 species of trees, 1 means pine trees, 2 means popular trees and 3 means willow trees.
// Divide the forst into x parts such that x people take care of it.
// The forst can be divided horizontally or vertically and each divison needs to divide the forst into two parts.
// If the division is hosrizontal, give the top one to one person and continue to divide the forest below.
// if the divison is vertical, give the lefft one to one person and continue to divide the right forest.
// You need to make sure that each divison has atleast one popular tree.

// calculate the number of divsions possible, return the result mod 10^9+7

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

long dividing_forest(vector<vector<int>> &forest, int x)
{
    int m = forest.size();
    
    int n = forest[0].size();
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(n + 1, vector<ll>(x + 1, 0)));
    dp[1][1][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= x; k++)
            {
                if (i == 1 && j == 1)
                    continue;
                if (forest[i - 1][j - 1] == 2)
                {
                    if (i > 1)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % (1000000007);
                    }
                    if (j > 1)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k - 1]) % (1000000007);
                    }
                }
                else
                {
                    if (i > 1)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % (1000000007);
                    }
                    if (j > 1)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k]) % (1000000007);
                    }
                }
            }
        }
    }
    return dp[m][n][x];
}

// int main()
// {
//     int m, n, x;
//     cin >> m >> n >> x;
//     vector<vector<int>> forest(m, vector<int>(n));
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> forest[i][j];
//         }
//     }
//     cout << dividing_forest(forest, x) << endl;
//     return 0;
// }

int main()
{
    vector<vector<int>> forest = {{1, 2, 3}, {2,1,2}, {3,1,1}};
    int x = 3;
    cout<<dividing_forest(forest, x);
    return 0;
}