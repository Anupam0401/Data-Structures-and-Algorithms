/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    void calculateCombSum2(int index, int target, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<arr.size();i++){
            if(i>index&&arr[i]==arr[i-1])   continue;
            if(arr[i]>target)   break;
            temp.push_back(arr[i]);
            calculateCombSum2(i+1,target-arr[i],arr,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        calculateCombSum2(0,target,candidates,temp,ans);
        return ans;
    }
};
// @lc code=end

