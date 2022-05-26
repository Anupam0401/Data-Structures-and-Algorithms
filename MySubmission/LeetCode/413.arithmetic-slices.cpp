/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int ans = 0;
        int index = 0;
        int diff = nums[1]-nums[0];
        for(int i=1;i<nums.size()-1;++i){
            if(nums[i+1]-nums[i]==diff){
                index++;
            }
            else{
                diff = nums[i+1]-nums[i];
                index=0;
            }
            ans+=index;
        }
        return ans;
    }
};
// @lc code=end

