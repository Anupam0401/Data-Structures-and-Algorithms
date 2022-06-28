/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        int n = nums.size();
        bool increasing = true, decreasing = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                increasing = false;
                break;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                decreasing = false;
                break;
            }
        }
        return increasing or decreasing;
    }
};
// @lc code=end
