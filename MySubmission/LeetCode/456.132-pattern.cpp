/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start

// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

// Return true if there is a 132 pattern in nums, otherwise, return false.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < s.top()) {
                while (!s.empty() && s.top() < nums[i]) {
                    if (nums[i] < s.top()) return true;
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end

