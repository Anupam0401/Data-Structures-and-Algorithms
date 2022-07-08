/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> store;
        vector<int> ans;
        for(auto i: nums)   store[i]++;
        for(auto x:store){
            if(x.second>n/3)    ans.push_back(x.first);
        }
        return ans;
    }
};
// @lc code=end

