/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */


// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if (n == 1) return true;
        vector<int> orderMap(26, 0);
        for (int i = 0; i < 26; i++) {
            orderMap[order[i] - 'a'] = i;
        }
        for (int i = 0; i < n-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            int len1 = word1.length();
            int len2 = word2.length();
            int j = 0;
            while (j < len1 && j < len2) {
                if (word1[j] != word2[j]) {
                    if (orderMap[word1[j] - 'a'] > orderMap[word2[j] - 'a']) {
                        return false;
                    }
                    break;
                }
                j++;
            }
            if (j == len2 && j < len1) return false;
        }
        return true;
    }
};
// @lc code=end

