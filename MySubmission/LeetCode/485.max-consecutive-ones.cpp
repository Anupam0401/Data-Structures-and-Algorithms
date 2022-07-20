/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, maxOnes = INT_MIN;
        for(int i=0;i<n;i++){
            curr = 0;
            while (i<n && nums[i]==1)
            {
                curr++;
                i++;
            }
            maxOnes = max(maxOnes,curr);
        }
        return maxOnes;
    }
};
// @lc code=end

