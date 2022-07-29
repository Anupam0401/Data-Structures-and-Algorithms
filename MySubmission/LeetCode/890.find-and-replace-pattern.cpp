/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
class Solution {
public:
    bool match(string s1, string s2){
        unordered_map<char,char> s1_s2, s2_s1;
        for(int i=0;i<s1.length();i++){
            if((s1_s2.count(s1[i])&&s1_s2[s1[i]]!=s2[i]) || (s2_s1.count(s2[i])&&s2_s1[s2[i]]!=s1[i])) return false;
            else{
                s1_s2[s1[i]] = s2[i];
                s2_s1[s2[i]] = s1[i];
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (int i = 0; i < words.size(); i++)
        {
            if(match(words[i],pattern)) res.push_back(words[i]);
        }
        return res;
    }
};
// @lc code=end

