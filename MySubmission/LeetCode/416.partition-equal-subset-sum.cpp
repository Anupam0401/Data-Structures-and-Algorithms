/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool one_partition(int ind, int target, vector<int>& nums){
        if(target == 0)
            return true;
        if(ind == 0)
            return nums[ind] == target;
        bool not_take = one_partition(ind-1, target, nums);
        bool take = false;
        if(target>=nums[ind])
            take = one_partition(ind-1, target-nums[ind], nums);
        return not_take || take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1)
            return false;
        return one_partition(nums.size()-1, sum/2, nums);
    }
};
// @lc code=end

