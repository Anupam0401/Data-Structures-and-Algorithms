/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        if(n==1)    return nums[0];
        int majority = nums[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(count == 0){
                majority = nums[i];
                count++;
            }
            else if(nums[i]==majority)  count++;
            else count--;
        }
        return majority;
    }
};
// @lc code=end
