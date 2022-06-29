/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start

// You are given a string s consisting only of letters 'a' and 'b'. In a single step you can remove one palindromic subsequence from s.

// Return the minimum number of steps to make the given string empty.

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return 2;
            i++;
            j--;
        }
        return 1;
    }
};
// @lc code=end

