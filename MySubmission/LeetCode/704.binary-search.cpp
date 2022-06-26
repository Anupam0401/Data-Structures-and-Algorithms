/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};
// @lc code=end

