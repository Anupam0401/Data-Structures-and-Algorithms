/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4)
            return res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // for(int k = j+1;k<n-1;k++){
                //     long long int sum = (long long)nums[i]+nums[j]+nums[k];
                //     long long int required =  - sum + (long long int)target;
                //     if(required < -1e9 || required > 1e9)
                //         continue;
                //     if(binary_search(nums.begin()+k+1,nums.end(),(int)required)){
                //         res.push_back({nums[i],nums[j],nums[k],(int)required});
                //     }
                // }
                int left = j+1, right = n-1;
                long long required = (long long)target - (long long)nums[i] - nums[j];
                while(left<right){
                    long long sum = (long long)nums[left]+nums[right];
                    if(sum==required){
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                    }
                    else if(sum<required)   left++;
                    else right --;
                }
            }
        }
        // remove duplicates from res
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};
// @lc code=end

