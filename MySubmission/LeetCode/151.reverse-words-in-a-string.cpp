/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        if(n==1)    return s;
        string ans = "";
        string temp = "";
        for(int i=0;i<n;i++){
            if(s[i]==32){
                if(!temp.empty())
                    ans = " "+temp+ans;
                temp = "";
            }
            else temp+=s[i];
        }
        if(!temp.empty())   ans = " "+temp+ans;
        ans=ans.substr(1);
        return ans;
    }
};
// @lc code=end

