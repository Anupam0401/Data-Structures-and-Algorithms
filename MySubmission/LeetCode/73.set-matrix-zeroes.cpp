/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void makeItNegative(vector<vector<int>> &matrix, int r, int c, int m, int n)
    {
        for (int i = 0; i < n; i++)
            matrix[r][i] = matrix[r][i]==0?0:INT_MIN;
        for (int i = 0; i < m; i++)
            matrix[i][c] = matrix[i][c]==0?0:INT_MIN;
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    makeItNegative(matrix, i, j, m, n);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == INT_MIN)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};
// @lc code=end

