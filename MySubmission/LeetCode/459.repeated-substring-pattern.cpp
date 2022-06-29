/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:

// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int i = 1;
        while (i <= n / 2) {
            if (n % i == 0) {
                int j = n / i;
                string t = s.substr(0, i);
                string u = "";
                for (int k = 0; k < j; k++) {
                    u += t;
                }
                if (u == s) {
                    return true;
                }
            }
            i++;
        }
        return false;
    }
};
// @lc code=end

