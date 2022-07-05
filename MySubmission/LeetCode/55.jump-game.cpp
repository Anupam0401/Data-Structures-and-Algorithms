/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool helper(int ind, vector<int>& nums, vector<int>& dp){
        if(ind >= nums.size()-1) return true;
        
        if(dp[ind] != -1) return dp[ind];
        bool val = false;
        for(int i=1; i<=nums[ind]; i++){
            val = val || helper(ind + i, nums, dp);
        }
        return dp[ind] = val;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};
// @lc code=end

