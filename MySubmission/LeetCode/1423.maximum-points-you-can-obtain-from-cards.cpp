/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int solve(vector<int>& cardPoints,int left, int right, int sum, int k,vector<vector<int>>& dp){
        if(k<=0)    return sum;
        if(dp[left][right]!=-1) return dp[left][right];
        int ls = solve(cardPoints, left+1,right,sum+cardPoints[left],k-1,dp);
        int rs = solve(cardPoints, left, right-1,sum+cardPoints[right],k-1,dp);
        return dp[left][right] = max(ls, rs);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(cardPoints,0,n-1,0,k,dp);
    }
};
// @lc code=end

