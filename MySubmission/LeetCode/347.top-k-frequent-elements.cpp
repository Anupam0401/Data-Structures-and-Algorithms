/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    // static bool comp(vector<int> &a, vector<int> &b){
    //     return a[1]>b[1];
    // }
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> mp;
    //     int n = nums.size();
    //     for(auto num:nums)  mp[num]++;
    //     vector<vector<int>> freq;
    //     for(auto &it : mp){
    //         freq.push_back({it.first,it.second});
    //     }
    //     sort(freq.begin(),freq.end(),comp);
    //     vector<int> res;
    //     for(auto it:freq){
    //         if(k--) res.push_back(it[0]);
    //         else break;
    //     }
    //     return res;
    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(auto num:nums)  mp[num]++;
        priority_queue<pair<int,int>> pq;
        for(auto &it: mp){
            pq.push(make_pair(it.second,it.first));
        }
        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

};
// @lc code=end

