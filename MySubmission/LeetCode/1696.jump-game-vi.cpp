/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
class Solution
{
public:
    int memoization(int ind, int k, vector<int> &nums, vector<int> &dp)
    {
        if (ind >= nums.size() - 1)
            return nums.back();
        if (dp[ind] != INT_MIN)
            return dp[ind];
        int score = INT_MIN;
        for (int i = 1; i <= k; i++)
        {
            score = max(score, nums[ind] + memoization(ind + i, k, nums, dp));
        }
        return dp[ind] = score;
    }
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(size(nums), INT_MIN);
        multiset<int> s({dp[0] = nums[0]}); // set dp[0] = nums[0] and insert it into set
        for (int i = 1; i < size(nums); i++)
        {
            if (i > k)
                s.erase(s.find(dp[i - k - 1]));     // erase elements from which we cant jump to current index
            s.insert(dp[i] = *rbegin(s) + nums[i]); // choose element with max score and jump from that to the current index
        }
        return dp.back();
    }
};
// @lc code=end
