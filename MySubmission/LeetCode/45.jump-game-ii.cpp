/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    int solve(int ind, vector<int> &nums, vector<int> &dp)
    {
        if (ind >= nums.size() - 1)
            return 0;
        if (dp[ind] != 10001)
            return dp[ind];
        for (int i = 1; i <= nums[ind]; i++)
        {
            dp[ind] = min(dp[ind], 1 + solve(ind + i, nums, dp));
        }
        return dp[ind];
    }
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        // vector<int> dp(n, 10001);
        // return solve(0, nums, dp);
        int i=0, lastJumped = 0, maxReach = 0, jumps=0;
        while(lastJumped<n-1){
            maxReach = max(maxReach,nums[i]+i);
            if(i==lastJumped){
                lastJumped = maxReach;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};
// @lc code=end
