/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
class Solution {
public:
    int solve(int ind, int k, vector<int>& nums, vector<int>& dp){
        if(ind>=nums.size()-1)  return nums.back();
        if(dp[ind]!=INT_MIN)    return dp[ind];
        int score = INT_MIN;
        for(int i=1;i<=k;i++){
            score = max(score,nums[ind]+solve(ind+i,k,nums,dp));
        }
        return dp[ind] = score;
    }
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1,INT_MIN);
        return solve(0,k,nums,dp);
    }
};
// @lc code=end

