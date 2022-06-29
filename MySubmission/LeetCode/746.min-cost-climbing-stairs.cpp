/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int a=cost[0],b=cost[1];
        for (int i = 2; i < n; i++)
        {
            int c = cost[i] + min(a,b);
            a=b;
            b=c;
        }
        return min(a,b);
    }
};
// @lc code=end
