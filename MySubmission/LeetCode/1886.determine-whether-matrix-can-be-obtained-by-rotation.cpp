/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

// @lc code=start
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat.size()!=target.size())   return false;
        int n = mat.size();
        vector<bool> rot(4,true);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]) rot[0]=false;
                if(mat[i][j]!=target[n-j-1][i]) rot[1]=false;
                if(mat[i][j]!=target[n-i-1][n-j-1]) rot[2]=false;
                if(mat[i][j]!=target[j][n-i-1]) rot[3]=false;
            }
        }
        return rot[0] or rot[1] or rot[2] or rot[3];
    }
};
// @lc code=end

