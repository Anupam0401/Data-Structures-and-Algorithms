/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1)    return 0;
        int minTillNow = prices[0];
        int ans = 0;
        for(int i=1;i<n;i++){
            if(prices[i]-minTillNow>0){
                int profit = prices[i] - minTillNow;
                ans+=profit;
                minTillNow = prices[i];
            }
            else{
                minTillNow = min(minTillNow,prices[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

