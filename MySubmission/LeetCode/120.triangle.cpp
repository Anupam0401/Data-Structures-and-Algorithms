/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        if(row==1)  return triangle[0][0];
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return solve(n-1,)
    }
};
// @lc code=end

