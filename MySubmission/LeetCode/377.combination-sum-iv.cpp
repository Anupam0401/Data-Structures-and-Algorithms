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
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target)   ans+=count(nums,target-nums[i],dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<uint> dp(target+1,0);
        // return count(nums, target, dp);
        // tabulation approach
        dp[0] = 1; // for target=0, we have 1 subset as the base case
        for(int t = 1;t<=target;t++){
            for(int i=0;i<n;i++){
                if(nums[i]<=t)
                    dp[t] +=dp[t-nums[i]];
            }
        }
        return dp[target];
    }
};
// @lc code=end
