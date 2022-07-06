/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

// @lc code=start
class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0] > 0;
        int positiveLen = 0, negativeLen = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                positiveLen = negativeLen = 0;
                continue;
            }
            if (nums[i] > 0)
            {
                positiveLen++;
                negativeLen = negativeLen > 0 ? negativeLen + 1 : 0;
            }
            else
            {
                swap(positiveLen, negativeLen);
                negativeLen++;
                positiveLen = positiveLen == 0 ? 0 : positiveLen + 1;
            }
            ans = max(ans, positiveLen);
        }
        return ans;
    }
};
// @lc code=end
