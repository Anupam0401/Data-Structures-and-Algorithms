/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        if(n==1) return false;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1)
            return false;
        // doing tabulation - bottom up approach
        int target = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(nums[0]<=target)
            dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                bool not_take = dp[i-1][t];
                bool take = false;
                if(nums[i]<=t)
                    take = dp[i-1][t-nums[i]];
                dp[i][t] = not_take || take;
            }
        }
        return dp[n-1][target];
    }
};
// @lc code=end

