/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

// @lc code=start
class Solution {
public:
    int countPalindrome(string s, int start, int end)
    {
        int count = 0;
        while (start >= 0 && end < s.length() && s[start] == s[end])
        {
            count++;
            start--;
            end++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += countPalindrome(s, i, i);
            ans += countPalindrome(s, i, i + 1);
        }
        return ans;
    }
};
// @lc code=end

