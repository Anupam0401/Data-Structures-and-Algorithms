/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int lr = 0, lc = 0, hr = r - 1, hc = c - 1;
        while (lr <= hr && lc <= hc) {
            int midr = (lr + hr) / 2;
            int midc = (lc + hc) / 2;
            if (matrix[midr][midc] == target) {
                return true;
            } else if (matrix[midr][midc] < target) {
                if(matrix)
            } else {
                hr = midr - 1;
                hc = midc - 1;
            }
        }
    }
};
// @lc code=end

