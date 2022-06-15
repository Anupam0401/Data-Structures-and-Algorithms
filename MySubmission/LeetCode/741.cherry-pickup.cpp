/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1)    return grid[0][0];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solveDown(grid,0,0,dp) + solveUp(grid,n-1,n-1,dp);
    }
};
// @lc code=end

