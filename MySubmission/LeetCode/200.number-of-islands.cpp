/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i=0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j]=='1'){
                    dfs_marking(grid,i,j,row,col);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs_marking(vector<vector<char>>& grid,int r, int c, int row, int col){
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]!='1')   return;
        grid[r][c] = '0';
        dfs_marking(grid,r+1,c,row,col);
        dfs_marking(grid,r-1,c,row,col);
        dfs_marking(grid,r,c+1,row,col);
        dfs_marking(grid,r,c-1,row,col);
    }
};
// @lc code=end

