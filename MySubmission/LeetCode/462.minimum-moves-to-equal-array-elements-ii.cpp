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

    //the approach below does the same in O(n) time complexity
    // int minMoves2(vector<int>& nums) {
    //     int n = nums.size(), steps = 0;
    //     //fixes the median element in the n/2 th position of the array rest stays the same
    //     nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); 
    //     int median = nums[n/2];
    //     for(int i=0; i<n; i++){
    //         steps += abs(nums[i] - median);
    //     }
    //     return steps;
    // }
};
// @lc code=end

