/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
public:
    int solve(vector<vector<int>> &grid,int i, int j1, int j2, vector<vector<vector<int>>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
            return -1e8;
        if(i==m-1)
            if(j1!=j2)
                return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
            else
                return dp[i][j1][j2] = grid[i][j1];
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi=-1e8;
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
            if(j1==j2)
                maxi = max(maxi, grid[i][j1] + solve(grid,i+1,j1+di,j2+dj,dp));
            else 
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(grid,i+1,j1+di,j2+dj,dp)); 
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, 0, 0, grid[0].size()-1, dp);
    }
};
// @lc code=end

