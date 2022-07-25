/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)    return {-1,-1};
        int start = -1,end=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                start=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else r=mid-1;
        }
        l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                end=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else r=mid-1;
        }
        return {start,end};
    }
};
// @lc code=end

