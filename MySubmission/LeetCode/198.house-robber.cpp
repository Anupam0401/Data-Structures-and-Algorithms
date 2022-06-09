/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    // int solve(int index,vector<int> &nums,vector<int> &dp){
    //     if(index >= nums.size()) return 0;
    //     if(dp[index] != -1) return dp[index];
    //     int ans = max(nums[index] + solve(index+2,nums,dp),solve(index+1,nums,dp));
    //     dp[index] = ans;
    //     return ans;
    // }
    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size()+1,-1);
    //     return solve(0,nums,dp);
    // }
    int rob(vector<int>& nums) {
        // do tabulation approach
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        // vector<int> dp(n+1,0);
        int a=0,b=nums[0];
        // dp[1] = nums[0];
        for(int i=2;i<=n;i++){
            int c = max(b,a+nums[i-1]);
            a=b;
            b=c;
        }
        return b;
    }
};
// @lc code=end

