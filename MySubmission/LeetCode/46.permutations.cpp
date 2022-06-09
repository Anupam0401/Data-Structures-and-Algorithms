/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    void getpermutation(vector<int> &nums,vector<bool> &freq, vector<int> &temp,vector<vector<int>> &ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i] = true;
                temp.push_back(nums[i]);
                getpermutation(nums,freq,temp,ans);
                freq[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> freq(nums.size(),false);
        getpermutation(nums,freq,temp,ans);
        return ans;
    }
};
// @lc code=end

