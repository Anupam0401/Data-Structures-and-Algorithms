/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
    int l1,l2,l3;
public:
    bool solve(int i1, int i2, int i3, string s1, string s2, string s3, vector<vector<vector<int>>>& dp){
        if(i3==l3-1){
            if(i1>l1-1)   return s2[l2-1]==s3[l3-1];
            else if(i2>l2-1)   return s1[l1-1]==s3[l3-1];
            return false;
        }
        if(dp[i1][i2][i3]!=-1)  return dp[i1][i2][i3];
        bool first = s1[i1]==s3[i3] and solve(i1+1,i2,i3+1,s1,s2,s3,dp);
        bool second = s2[i2]==s3[i3] and solve(i1,i2+1,i3+1,s1,s2,s3,dp);
        return dp[i1][i2][i3] = first or second;
    }
    bool isInterleave(string s1, string s2, string s3) {
        l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l3!=l1+l2)   return false;
        if(l3==0)   return true;
        vector<vector<vector<int>>> dp(l1+1,vector<vector<int>>(l2+1,vector<int>(l3+1,-1)));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};
// @lc code=end

