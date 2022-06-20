/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> S;
        for(int i=0;i<nums.size();i++) {
            if(S.find(nums[i])!=S.end()) return true;
            S.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

