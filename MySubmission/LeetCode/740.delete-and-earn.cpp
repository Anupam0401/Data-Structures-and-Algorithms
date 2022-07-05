/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, int> dp;
    unordered_map<int, int> hash;

public:
    int solve(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
        {
            if (hash.find(1) != hash.end())
                return hash[1];
            return 0;
        }
        if (dp.find(n) != dp.end())
            return dp[n];
        int gain = 0;
        if (hash.find(n) != hash.end())
            gain = hash[n];
        return dp[n] = max(solve(n - 1), solve(n - 2) + gain);
    }
    int tabulation(int n)
    {
        dp[0] = 0;
        dp[1] = hash.find(1) != hash.end() ? hash[1] : 0;
        for (int i = 2; i <= n; i++)
        {
            int gain = 0;
            if (hash.find(i) != hash.end())
                gain = hash[i];
            dp[i] = max(dp[i - 1], gain + dp[i - 2]);
        }
        return dp[n];
    }
    int spaceOptimizedTabulation(int n){
        int a = 0;
        int b = hash.find(1) != hash.end() ? hash[1] : 0;
        for (int i = 2; i <= n; i++)
        {
            int gain = 0;
            if (hash.find(i) != hash.end())
                gain = hash[i];
            int c = max(b, gain + a);
            a=b;
            b=c;
        }
        return b;
    }
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        int maxNum = INT_MIN;
        for (auto x : nums)
        {
            hash[x] += x;
            maxNum = max(maxNum, x);
        }
        // return solve(maxNum);
        // return tabulation(maxNum);
        return spaceOptimizedTabulation(maxNum);
    }
};
// @lc code=end
