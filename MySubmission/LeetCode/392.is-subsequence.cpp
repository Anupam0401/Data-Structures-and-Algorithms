/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        if(s.length() > t.length()) return false;
        int k=0;
        for(int i=0;i<t.length();i++){
            if(s[k]==t[i])  k++;
            if(k==s.length()) return true;
        }
        return false;
    }
};
// @lc code=end

