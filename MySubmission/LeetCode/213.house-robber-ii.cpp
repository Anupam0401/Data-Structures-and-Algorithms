/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    // memoization aaproach
    int solve(int index, int n, vector<int> &nums, vector<int> &dp){
        if(index >= n) return 0;
        if(dp[index]!=-1) return dp[index];
        int include;
        // if(index==0)    include = nums[index] + solve(index+2,--n,nums,dp);
        // else include = nums[index] + solve(index+2,n,nums,dp);
        include = nums[index] + solve(index+2,n,nums,dp);
        int exclude = solve(index+1,n,nums,dp);
        return dp[index] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        int n=nums.size();
        vector<int> dp(nums.size()+1,-1);
        int x = solve(1, n, nums, dp);
        for(int i=0; i<=n; i++) dp[i] = -1;
        int y = solve(0, n-1, nums, dp);
        return max(x,y);
    }
};
// @lc code=end

