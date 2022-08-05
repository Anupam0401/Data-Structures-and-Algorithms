/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution
{
public:
    int count(vector<int> &nums, int target, vector<int>& dp)
    {
        if (target == 0)
            return 1;
        if(dp[target]!=-1)  return dp[target];
        int ans = 0;
        for(auto &i:nums){
            if(i<=target)   ans+=count(nums,target-i,dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return count(nums, target, dp);
    }
};
// @lc code=end
