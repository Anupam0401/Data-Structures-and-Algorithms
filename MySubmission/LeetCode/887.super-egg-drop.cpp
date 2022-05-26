/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

// Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// @lc code=start
class Solution
{
public:
    int superEggDrop(int K, int N)
    {
        // vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        // int ans = INT_MAX, i, j;
        // for (i = 1; i <= n; i++)
        // {
        //     dp[i][1] = 1;
        //     dp[i][0] = 0;
        // }

        // // We always need j trials for one egg
        // // and j floors.
        // for (j = 1; j <= k; j++)
        //     dp[1][j] = j;

        // // Fill rest of the entries in table using
        // // optimal substructure property
        // for (i = 2; i <= n; i++)
        // {
        //     for (j = 2; j <= k; j++)
        //     {
        //         dp[i][j] = INT_MAX;
        //         for (int x = 1; x <= j; x++)
        //         {
        //             ans = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
        //             if (ans < dp[i][j])
        //                 dp[i][j] = ans;
        //         }
        //     }
        // }
        // return dp[n][k]+1;
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
    }
};
// @lc code=end
