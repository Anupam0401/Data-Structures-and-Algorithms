/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // int i = 0, j = matrix[0].size() - 1;
        // while (i < matrix.size() && j >= 0)
        // {
        //     if (matrix[i][j] == target)
        //         return true;
        //     else if (matrix[i][j] > target)
        //         j--;
        //     else if (matrix[i][j] < target)
        //         i++;
        // }
        // return false;
        // using binary search on the whole matrix at once
        // Time complexity: O(log(rw*cl))
        int r = matrix.size(), c = matrix[0].size();
        int left = 0, right = (r * c) - 1;
        while (left <= right)
        {
            int mid = (left + (right - left) / 2);
            int i = mid / c, j = mid % c;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
// @lc code=end
