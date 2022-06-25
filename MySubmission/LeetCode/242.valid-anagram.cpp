/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int len_s = s.length();
        int len_t = t.length();
        if (len_s != len_t)
            return false;
        int n = len_s;
        int store[26] = {0};
        for (int i = 0; i < n; i++)
        {
            store[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            store[t[i] - 'a']--;
            if (store[t[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
