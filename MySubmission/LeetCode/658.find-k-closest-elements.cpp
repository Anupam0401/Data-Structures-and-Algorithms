/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n<=k)    return arr;
        vector<pair<int,int>> num_diff;
        for(int i=0;i<n;i++){
            num_diff.push_back({arr[i],abs(arr[i]-x)});
        }
        sort(num_diff.begin(),num_diff.end(),[](const pair<int,int> &a, const pair<int,int> &b){
            if(a.second==b.second)   return a.first<b.first;
            return a.second<b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(num_diff[i].first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

