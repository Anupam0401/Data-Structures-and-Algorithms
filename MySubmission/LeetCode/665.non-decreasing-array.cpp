/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                cnt++;
                if (i - 2 < 0 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i]; // modify nums[i-1] of a priority
                else
                    nums[i] = nums[i - 1]; // have to modify nums[i]
            }
            if (cnt > 1)
                return false;
        }
        return true;
    }
};
// @lc code=end
