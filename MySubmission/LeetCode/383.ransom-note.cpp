/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int beta[26] = {0};
        // char baap[26] = {0};
        for(int i=0;i<magazine.size();i++){
            beta[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(beta[ransomNote[i]-'a']==0)  return false;
            beta[ransomNote[i]-'a']--;
        }
        return true;
    }
};
// @lc code=end

