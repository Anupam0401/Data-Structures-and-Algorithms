/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution
{
    int row, col;

public:
    int dfs_explore(int r, int c, vector<vector<int>> &grid)
    {
        if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == 0)
            return 1;
        if (grid[r][c] == -1)
            return 0;
        grid[r][c] = -1;
        int count = (dfs_explore(r + 1, c, grid) + dfs_explore(r - 1, c, grid) + dfs_explore(r, c + 1, grid) + dfs_explore(r, c - 1, grid));
        return count;
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        int maxPerimeter = 0;
        bool flag = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    maxPerimeter = dfs_explore(i, j, grid);
                    flag=1;
                    break;
                }
            }
            if(flag)    break;
        }
        return maxPerimeter;
    }
};
// @lc code=end
