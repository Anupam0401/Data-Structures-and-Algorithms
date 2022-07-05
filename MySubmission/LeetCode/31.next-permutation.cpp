/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1])   i--;
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i])  j--;
            swap(nums[i],nums[j]);
        }
        // reverse from i+1 th index
        reverse(nums,i+1);
    }
};
// @lc code=end

