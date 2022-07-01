/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */


// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 
// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_len = 0;
        int max_count = 0;
        int start = 0;
        int end = 0;
        int count[26] = {0};
        while(end<n){
            count[s[end]-'A']++;
            max_count = max(max_count, count[s[end]-'A']);
            end++;
            while(end-start-max_count>k){
                count[s[start]-'A']--;
                start++;
            }
            max_len = max(max_len, end-start);
        }
        return max_len; 
    }
};
// @lc code=end

