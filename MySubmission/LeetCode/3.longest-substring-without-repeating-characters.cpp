/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1) return s.length();
        unordered_set<char> uniq;
        int maxLen = 1,i=0,j=0,n=s.length();
        while(i<n&&j<n){
            if(uniq.find(s[i])==uniq.end()){
                uniq.insert(s[i]);
                i++;
                maxLen = max(maxLen,i-j);
            }
            else{
                uniq.erase(s[j]);
                j++;
            }
        }
        return maxLen;
    }
};
// @lc code=end

