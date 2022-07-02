/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto &w:words){
            m[w]++;
        }
        vector<pair<string,int>> v;
        for(auto &p:m){
            v.push_back(p);
        }
        sort(v.begin(),v.end(),[](const pair<string,int> &a,const pair<string,int> &b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        });
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
// @lc code=end

