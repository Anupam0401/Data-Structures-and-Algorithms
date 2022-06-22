/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool one_partition(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0)
            return true;
        if(ind == 0)
            return nums[ind] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        bool not_take = one_partition(ind-1, target, nums, dp);
        bool take = false;
        if(target>=nums[ind])
            take = one_partition(ind-1, target-nums[ind], nums,dp);
        return dp[ind][target] = not_take || take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1)
            return false;
        vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));
        return one_partition(nums.size()-1, sum/2, nums,dp);
    }
};
// @lc code=end

