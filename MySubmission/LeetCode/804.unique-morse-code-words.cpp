/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int n = words.size();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=0;j<words[i].size();j++){
                temp+=morse[words[i][j]-'a'];
            }
            st.insert(temp);
        }
        return st.size();
    }
};
// @lc code=end

