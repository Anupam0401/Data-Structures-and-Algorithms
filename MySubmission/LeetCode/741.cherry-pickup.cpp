/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=start
class Solution {
public:
    int solveDown(vector<vector<int>> &grid, int r,int c, vector<vector<int>> &dp){
        if(r==grid.size()-1 && c==grid[0].size()-1){
            return grid[r][c]>0?grid[r][c]--:0;
        }
        if(dp[r][c]!=-1)    // if already calculated
            return dp[r][c];
        int val = 0;
        // go right
        if(grid[r][c+1]!=-1 && c+1<grid[0].size()){
            val = grid[r][c] + solveDown(grid,r,c+1,dp);
            grid[r][c]=0;
        }
        // go down 
        if(grid[r+1][c]!=-1 && r+1<grid.size()){
            val = max(val, grid[r][c] + solveDown(grid,r+1,c,dp));
            grid[r][c]=0;
        }
        return dp[r][c] = val;
    }
    // now same as solveDown but with different starting point and the direction is up and left
    int solveUp(vector<vector<int>> &grid, int r,int c, vector<vector<int>> &dp){
        if(r==0 && c==0){
            return grid[r][c]>0?grid[r][c]--:0;
        }
        if(dp[r][c]!=-1)    // if already calculated
            return dp[r][c];
        int val = 0;
        // go left
        if(grid[r][c-1]!=-1 && c-1>=0){
            val = grid[r][c] + solveUp(grid,r,c-1,dp);
            grid[r][c]=0;
        }
        // go up 
        if(grid[r-1][c]!=-1 && r-1>=0){
            val = max(val, grid[r][c] + solveUp(grid,r-1,c,dp));
            grid[r][c]=0;
        }
        return dp[r][c] = val;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1)    return grid[0][0];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> dp_up(n,vector<int>(n,-1));
        return solveDown(grid,0,0,dp) + solveUp(grid,n-1,n-1,dp_up);
    }
};
// @lc code=end

