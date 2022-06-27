/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution {
public:
    int minPartitions(string s) {
        int n = s.length();
        int ans=-1;
        for(int i=0;i<n;i++){
            ans = max(ans,s[i]-'0');
        }
        return ans;
    }
};
// @lc code=end

