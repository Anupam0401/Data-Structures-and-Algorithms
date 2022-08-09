/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution
{
public:
    int recursMemo(int ind1, int ind2, string &a, string &b, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (a[ind1] == b[ind2])
            return dp[ind1][ind2] = 1 + recursMemo(ind1 - 1, ind2 - 1, a, b, dp);
        else
            return dp[ind1][ind2] = max(recursMemo(ind1 - 1, ind2, a, b, dp), recursMemo(ind1, ind2 - 1, a, b, dp));
    }
    int longestCommonSubsequence(string a, string b)
    {
        int l1 = a.length();
        int l2 = b.length();
        if (l1 == 0 || l2 == 0)
            return 0;
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        return recursMemo(l1 - 1, l2 - 1, a, b, dp);
    }
};
// @lc code=end
