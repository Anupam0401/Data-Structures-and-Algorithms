/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */


// @lc code=start
class Solution {
public:

// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum>=x){
                ans += (sum-x);
                sum = x;
            }
        }
        if(sum>0) return -1;
        return ans;
    }
};
// @lc code=end

