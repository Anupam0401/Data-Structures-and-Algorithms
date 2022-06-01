/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    void calculateCombSum(int index, vector<int> &arr, int target, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (index == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
                return;
            }
            return;
        }
        if (arr[index] <= target)
        {
            temp.push_back(arr[index]);
            calculateCombSum(index, arr, target - arr[index], temp, ans);
            temp.pop_back();
        }
        calculateCombSum(index + 1, arr, target,temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        calculateCombSum(0, candidates, target, temp, ans);
        return ans;
    }
};
// @lc code=end
