/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1,0);
        for(auto i:nums) hash[i]++;
        for(int i=1;i<n+1;i++){
            if(hash[i]>1){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

