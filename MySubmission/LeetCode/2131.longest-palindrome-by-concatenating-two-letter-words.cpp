/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        vector<vector<int>> hash(26, vector<int>(26, 0));
        for (auto word : words)
        {
            hash[word[0] - 'a'][word[1] - 'a']++;
        }
        int ans = 0;
        bool central = false;
        for (int i = 0; i < 26; i++)
        {
            if (hash[i][i])
            {
                if (hash[i][i] % 2 == 0)
                {
                    ans += hash[i][i];
                }
                else
                {
                    ans += hash[i][i] - 1;
                    central = true;
                }
            }
            for (int j = i + 1; j < 26; j++)
            {
                if (hash[i][j])
                {
                    ans += 2 * min(hash[i][j], hash[j][i]);
                }
            }
        }
        if (central)
            ans++;
        return 2 * ans;
    }
};
// @lc code=end
