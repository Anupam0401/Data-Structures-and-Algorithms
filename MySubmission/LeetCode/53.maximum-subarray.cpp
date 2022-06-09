/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum=0,sum=INT_MIN;
        for(int i=0;i<n;i++){
            currSum = max(nums[i],nums[i]+currSum);
            sum = max(sum,currSum);
        }
        return sum;
    }
};
// @lc code=end

