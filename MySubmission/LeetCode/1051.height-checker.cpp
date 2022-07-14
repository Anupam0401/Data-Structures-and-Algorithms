/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> map(101, 0);
        for (int i = 0; i < n; i++)
            map[heights[i]]++;
        int count = 0;
        int j = 1;
        for (int i = 0; i < n; i++)
        {
            while (map[j] == 0)
                j++;
            if (j != heights[i])
                count++;
            map[j]--;
        }
        return count;
    }
};
// @lc code=end
