/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
            return 0;
        // vector<int> s0(n,0);
        // vector<int> s1(n,-prices[0]);
        // vector<int> s2(n,INT_MIN);
        // for(int i=1;i<n;i++){
        //     s0[i] = max(s0[i-1],s2[i-1]);
        //     s1[i] = max(s1[i-1],s0[i-1]-prices[i]);
        //     s2[i] = s1[i-1]+prices[i];
        // }
        // return max(s0.back(),s2.back());
        int a = 0, b = -prices[0], c = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            int temp1 = max(a, c);
            int temp2 = max(b, a - prices[i]);
            int temp3 = b + prices[i];
            a = temp1, b = temp2, c = temp3;
        }
        return max(a, c);
    }
};
// @lc code=end