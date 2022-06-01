/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */


// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        unordered_set<string> set;
        for(int i=0; i<s.size()-k+1; i++){
            set.insert(s.substr(i, k));
        }
        return set.size() == pow(2, k);
    }
};
// @lc code=end

