/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> freq;
        for(auto it:mp){
            freq.push_back({it.second,it.first});
        }
        sort(freq.begin(),freq.end(),[](pair<int,int> a,pair<int,int> b){
            return a.first>b.first;
        });
        int count=0;
        int i = 0;
        int res=0;
        while(count<n/2){
            res++;
            count+=freq[i++].first;
        }
        return res;
    }
};
// @lc code=end

