/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        set<int> S;
        for(int i=0; i<nums.size(); i++){
            if(S.find(nums[i]) == S.end()){
                S.insert(nums[i]);
            }
            else{
                S.erase(nums[i]);
            }
        }
    }
};
// @lc code=end

