/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        if(n==1)    return 0;
        int count[26] = {0};
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(count[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

