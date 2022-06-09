/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)    return 0;
        int least = INT_MAX;
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            least = min(least, prices[i]);
            ans = max(prices[i]-least,ans);
        }
        return ans;
    }
};
// @lc code=end

