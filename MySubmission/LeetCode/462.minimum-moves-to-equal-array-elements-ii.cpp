/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return 0;
        sort(nums.begin(),nums.end());
        int l = 0, r = n-1;
        int ans = 0;
        while(l<r){
            ans+= nums[r--]-nums[l++];
        }
        return ans;
    }
};
// @lc code=end

