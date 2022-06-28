/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int get_minCost(int index,vector<int>& cost, vector<int>& dp){
        if(index<0) return 0;
        if(index==0||index==1)  return cost[index];
        if(dp[index]!=-1)   return dp[index];
        return dp[index] = cost[index]+min(get_minCost(index-1,cost,dp),get_minCost(index-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(get_minCost(n-1,cost,dp),get_minCost(n-2,cost,dp));
    }
    }
};
// @lc code=end

