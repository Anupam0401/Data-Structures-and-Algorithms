/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution
{
public:
    // Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

    // An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        int s_len = s.length(), p_len = p.length();
        if (s_len < p_len)
            return result;
        int left = 0, right = 0;
        int freq[26];
        for (int i = 0; i < p_len; i++)
            freq[p[i] - 'a']++;
        int count = p_len;
        while (right < s_len)
        {
            if (freq[s[right++] - 'a']-- >= 1){
                count--;
                // freq[s[right] - 'a']--;
            }
            if (count == 0)
                result.push_back(left);
            if (right - left == p_len && freq[s[left] - 'a'] >= 0){
                count++;
                freq[s[left] - 'a']++;
                left++;
            }
            // right++;
        }
        return result;
    }
};
// @lc code=end
