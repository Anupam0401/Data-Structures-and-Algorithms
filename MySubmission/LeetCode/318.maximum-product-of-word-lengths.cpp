/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> mask(n, 0);
        for (int i = 0; i < n; i++)
        {
            int len = words[i].size();
            for (int j = 0; j < len; j++)
            {
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((mask[i] & mask[j]) == 0)
                {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

