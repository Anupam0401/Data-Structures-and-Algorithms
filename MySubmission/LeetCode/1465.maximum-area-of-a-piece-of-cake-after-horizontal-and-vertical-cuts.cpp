/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
class Solution
{
    const long long int mod = 1e9 + 7;

public:
    int sub(int a, int b)
    {
        a -= b;
        return (a < 0 ? a + mod : a);
    }

    int mul(long long int a, long long int b)
    {
        a *= b;
        return (a >= mod ? a % mod : a);
    }
    int maxArea(int h, int w, vector<int> &hor, vector<int> &ver)
    {
        hor.push_back(0);
        hor.push_back(h);
        ver.push_back(0);
        ver.push_back(w);
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        int ans = INT_MIN;
        for (int i = 0; i < hor.size() - 1; i++)
        {
            for (int j = 0; j < ver.size() - 1; j++)
            {
                ans = max(ans, mul(hor[i + 1]- hor[i], (ver[j + 1]- ver[j])));
            }
        }
        return ans % mod;
    }
};
// @lc code=end
