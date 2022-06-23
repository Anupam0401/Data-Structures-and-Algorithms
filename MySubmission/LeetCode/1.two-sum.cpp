/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            if (m.find(nums[i]) != m.end())
                return vector<int>{m[nums[i]], i};
            m[target - nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end
