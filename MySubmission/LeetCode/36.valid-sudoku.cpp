/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // check row wise
        for (int i = 0; i < 9; i++)
        {
            unordered_set<int> s;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (s.find(num) != s.end())
                        return false;
                    s.insert(num);
                }
            }
        }
        // check column wise
        for (int j = 0; j < 9; j++)
        {
            unordered_set<int> s;
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (s.find(num) != s.end())
                        return false;
                    s.insert(num);
                }
            }
        }
        // check 3x3
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                unordered_set<int> s;
                for (int p = i; p < i + 3; p++)
                {
                    for (int q = j; q < j + 3; q++)
                    {
                        cout<<p<<" "<<q<<endl;
                        int num = board[p][q] - '0';
                        if (s.find(num) != s.end())
                            return false;
                        s.insert(num);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
