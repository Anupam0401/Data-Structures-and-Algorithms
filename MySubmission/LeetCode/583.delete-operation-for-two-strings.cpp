/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

// @lc code=start
class Solution
{
public:
    int minDistance(string &word1, string &word2)
    {
        return solve(word1, word2, 0, 0);
    }
    // recursive solver to find minimum deletions to equalize w1 & w2
    int solve(string w1, string w2, int i, int j)
    {
        if (i == size(w1) && j == size(w2))
            return 0; // reached end of both strings -> both strings have been equalized and no further steps required
        if (i == size(w1))
            return size(w2) - j; // reached end of word1 -> need to delete remaining characters of word2 to equalize
        if (j == size(w2))
            return size(w1) - i; // reached end of word2 -> need to delete remaining characters of word1 to equalize
        if (w1[i] == w2[j])
            return solve(w1, w2, i + 1, j + 1); // no deletion required since the characters already match
        // 1 current character deletion + min(after deleting w1[i], after deleting w2[j])
        return 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
    }
};
// @lc code=end
