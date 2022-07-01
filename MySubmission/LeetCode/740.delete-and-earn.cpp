/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int solve(vector<int>& nums, int index, int points){
        if(index==0)    return points;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return solve(nums,n-1,0);
    }
};
// @lc code=end

