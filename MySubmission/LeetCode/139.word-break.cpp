/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto i : wordDict)  st.insert(i);
        return checkBreak(s,st);
    }
    bool checkBreak(string s, set<string> st){
        int l = s.length();
        // if(l==0)    return true;
        // for(int i=1;i<=l;i++){
        //     if(st.count(s.substr(0,i))==1 && checkBreak(s.substr(i), st))   return true;
        // }
        // return false;
        vector<bool> dp(l+1,false);
        dp[0] = true;
        for(int i = 1;i<=l;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] && st.count(s.substr(j,i-j))==1){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[l];
    }
};
// @lc code=end

