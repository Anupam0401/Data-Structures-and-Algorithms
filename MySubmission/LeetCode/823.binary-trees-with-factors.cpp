/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &a)
    {
        int n = a.size();
        const long MOD = 1e9 + 7;
        if (n == 1)
            return 1;
        long res = 0;
        sort(a.begin(), a.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < n; i++)
        {
            dp[a[i]] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[i] % a[j] == 0)
                    dp[a[i]] = (dp[a[i]] + dp[a[j]] * dp[a[i] / a[j]]) % MOD;
            }
            res = (res + dp[a[i]]) % MOD;
        }
        return res;
    }
};
// @lc code=end
