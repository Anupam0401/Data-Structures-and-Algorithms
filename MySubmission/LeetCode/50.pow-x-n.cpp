/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        while (n)
        {
            if (n % 2)
                ans = n > 0 ? ans * x : ans / x;
            n = n / 2;
            x = x * x;
        }
        return ans;
    }
};
// @lc code=end
