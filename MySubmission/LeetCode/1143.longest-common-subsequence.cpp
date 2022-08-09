/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int recursive(int ind1,int ind2, string a, string b){
        if(ind1<0 || ind2<0)    return 0;
        if(a[ind1]==b[ind2])    return 1+recursive(ind1-1,ind2-1,a,b);
        else    return max(recursive(ind1-1,ind2,a,b),recursive(ind1,ind2-1,a,b));
    }
    int longestCommonSubsequence(string a, string b) {
        int l1 = a.length();
        int l2 = b.length();
        if(l1==0 || l2==0)  return 0;
        return recursive(l1-1,l2-1,a,b);
    }
};
// @lc code=end

