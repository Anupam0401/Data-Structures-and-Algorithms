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
        if(n==1)    return heights[0];
        vector<int> dp(n,0);
        // for(int i=0;i<n;i++){
        //     dp[i] = heights[i];
        // }
        int maxArea = heights[0];
        for(int i=1;i<n;i++){
            int minTillNow = heights[i];
            for(int j=i-1;j >= 0; j--){
                minTillNow = min(minTillNow,heights[j]);
                dp[i] = max(heights[i],max(minTillNow*(i-j+1),dp[i]));
            }
            maxArea = max(maxArea,max(minTillNow*(i+1),dp[i]));
        }
        return maxArea;
    }
};
// @lc code=end

