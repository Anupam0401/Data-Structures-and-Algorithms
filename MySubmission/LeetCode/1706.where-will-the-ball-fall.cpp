/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> ans;
        for(int j=0;j<col;j++){
            int currCol = j;
            for(int i=0;i<row;i++){
                int nextCol = currCol + grid[i][currCol];
                if(nextCol<0 || nextCol>=col || grid[i][currCol]!=grid[i][nextCol]){
                    currCol = -1;
                    break;
                }
                currCol = nextCol;
            }
            ans.push_back(currCol);
        }
        return ans;
    }
};
// @lc code=end

