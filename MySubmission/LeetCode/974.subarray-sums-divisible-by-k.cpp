/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int count = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            if (m.find(rem) != m.end())
            {
                count += m[rem];
                m[rem]++;
            }
            else
                m[rem] = 1;
        }
        return count;
    }
};
// @lc code=end

