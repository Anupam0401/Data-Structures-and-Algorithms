/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int sum = INT_MIN, currSum = 0, totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            currSum = max(nums[i], currSum + nums[i]);
            sum = max(sum, currSum);
            totalSum+=nums[i];
        }
        int minSum=INT_MAX;
        currSum = 0;
        for (int i = 0; i < n; i++)
        {
            currSum = min(nums[i], currSum + nums[i]);
            minSum = min(minSum, currSum);
        }
        return max(sum,(totalSum-minSum==0)?INT_MIN:totalSum-minSum);
    }
};
// @lc code=end
