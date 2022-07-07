/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int zeros = 0, ones = 0, twos = n - 1;
        while (ones <= twos)
        {
            if (nums[ones] == 0)
                swap(nums[ones++], nums[zeros++]);
            else if (nums[ones] == 1)
                ones++;
            else
                swap(nums[ones], nums[twos--]);
        }
    }
};
// @lc code=end
