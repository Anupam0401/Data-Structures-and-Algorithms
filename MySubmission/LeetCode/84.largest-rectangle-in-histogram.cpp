/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            dp[i] = heights[i];
        }
        int maxArea = 0;
        for(int i=1;i<n;i++){
            int minTillNow = dp[i];
            for(int j=i-1;i >= 0; i--){
                minTillNow = min(minTillNow,dp[j]);
            }
        }
    }
};
// @lc code=end

