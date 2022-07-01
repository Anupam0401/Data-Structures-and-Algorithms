/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution
{
public:
    string effectiveString(string s){
        string t = "";
        for(int i=0;i<s.length();i++){
            if(s[i]!='#')  t+=s[i];
            else if(s[i]=='#'&&t.length()!=0){
                t=t.substr(0,t.length()-1);
            }
        }
        return t;
    }
    bool backspaceCompare(string s, string t) {
        s = effectiveString(s);
        t = effectiveString(t);
        // cout<<s<<" "<<t<<endl;
        return s==t;
    }
};
// @lc code=end
