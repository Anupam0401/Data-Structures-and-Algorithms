/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution
{
    int l1, l2, l3;

public:
    bool solve(int i1, int i2, int i3, string s1, string s2, string s3, vector<vector<vector<int>>> &dp)
    {
        if (i3 == l3 - 1)
        {
            if (i1 > l1 - 1)
                return s2[l2 - 1] == s3[l3 - 1];
            else if (i2 > l2 - 1)
                return s1[l1 - 1] == s3[l3 - 1];
            return false;
        }
        if (dp[i1][i2][i3] != -1)
            return dp[i1][i2][i3];
        bool first = s1[i1] == s3[i3] and solve(i1 + 1, i2, i3 + 1, s1, s2, s3, dp);
        bool second = s2[i2] == s3[i3] and solve(i1, i2 + 1, i3 + 1, s1, s2, s3, dp);
        return dp[i1][i2][i3] = first or second;
    }
    bool isInterleave(string s1, string s2, string s3)
    {

        if (s3.length() != s1.length() + s2.length())
            return false;

        bool table[s1.length() + 1][s2.length() + 1];

        for (int i = 0; i < s1.length() + 1; i++)
            for (int j = 0; j < s2.length() + 1; j++)
            {
                if (i == 0 && j == 0)
                    table[i][j] = true;
                else if (i == 0)
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if (j == 0)
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                else
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }

        return table[s1.length()][s2.length()];
    }
};
// @lc code=end
