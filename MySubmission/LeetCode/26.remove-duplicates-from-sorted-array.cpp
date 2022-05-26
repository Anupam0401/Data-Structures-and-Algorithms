/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=1;
        int t=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=t){
                n++;
                t=nums[i];
                nums[n-1]=t;
            }
        }
        return n;
    }
};
// @lc code=end

