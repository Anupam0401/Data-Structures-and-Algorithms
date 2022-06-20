/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> m;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()){
                if(m.find(t[i]) == m.end()) m[s[i]] = t[i];
                else return false;
            }
            else{
                if(m[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

