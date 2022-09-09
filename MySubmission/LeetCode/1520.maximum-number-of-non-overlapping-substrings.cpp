/*
 * @lc app=leetcode id=1520 lang=cpp
 *
 * [1520] Maximum Number of Non-Overlapping Substrings
 */

// @lc code=start
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int l[26,INT_MAX], r[26,-1];
        int n = s.length();
        for(int i=0;i<n;i++){
            l[s[i]-'a'] = min(l[s[i]-'a'],i);
            r[s[i]-'a'] = i;
        }
        
    }
};
// @lc code=end

