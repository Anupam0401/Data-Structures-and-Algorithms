/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start

// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

class Solution {
public:
    // int longestStrChain(vector<string>& words) {
    //     int n = words.size();
    //     if(n == 0)
    //         return 0;
    //     if(n == 1)
    //         return 1;
    //     sort(words.begin(), words.end());
    //     int ans = 1;
    //     unordered_map<string, int> mp;
    //     for(int i = 0; i < n; i++){
    //         mp[words[i]] = i;
    //     }
    //     for(int i = 0; i < n; i++){
    //         int len = words[i].length();
    //         for(int j = 0; j < len; j++){
    //             string s = words[i];
    //             s.erase(j, 1);
    //             if(mp.find(s) != mp.end()){
    //                 ans = max(ans, i + 1);
    //             }
    //         }
    //     }
    //     return ans;
    // }
    bool isPredecessor(string s1, string s2){
        int len = s1.length();
        for(int i = 0; i < len; i++){
            string s = s1;
            s.erase(i, 1);
            if(s == s2)
                return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        //start from the largest sized word and delete characters from it to get the smaller strings
        for(int i=n-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(isPredecessor(words[i],words[j])){
                    words[i].erase(0,1);
                }
            }
        }
        int max = 0;
        for(int i=0;i<n;i++){
            if(words[i].length() > max)
                max = words[i].length();
        }
        return max;
    }
};
// @lc code=end

