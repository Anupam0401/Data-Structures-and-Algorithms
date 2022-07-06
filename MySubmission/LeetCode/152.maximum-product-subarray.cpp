/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        int currMax = 1, currMin = 1;
        int res = *max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int temp = currMax*nums[i];
            currMax = max({currMax*nums[i],nums[i],currMin*nums[i]});
            currMin = min({temp, nums[i], currMin*nums[i]});
            res = max(res,currMax);
        }
        return res;
    }
};
// @lc code=end

