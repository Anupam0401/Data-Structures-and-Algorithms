/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
    int row,col;
public:
    recursive approach
    int dfs_explore(int r,int c,vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]==0) return 0;
        grid[r][c]=0;
        return 1 + dfs_explore(r+1,c,grid) + dfs_explore(r-1,c,grid) + dfs_explore(r,c+1,grid) + dfs_explore(r,c-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    ans = max(ans,dfs_explore(i,j,grid));
                }
            }
        } 
        return ans;
    }
};
// @lc code=end

