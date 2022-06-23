/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        if (s.length() <= 1)
            return s.length();
        int ans = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) == m.end())
            {
                m[s[i]] = 1;
            }
            else
            {
                m[s[i]]++;
            }
        }
        int odd = 0, even = 0;
        if(m.size() == 1)
            return s.length();
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second >= 2)
            {
                if (it->second % 2 == 0)
                    even += it->second;
                else
                    even += it->second - 1, odd+=1;
            }
            else
                odd++;
        }
        if (odd > 0)
            ans = even + 1;
        else
            ans = even;
        return ans;
    }
};
// @lc code=end
