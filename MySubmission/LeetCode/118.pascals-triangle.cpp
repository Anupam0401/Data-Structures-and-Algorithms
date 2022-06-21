/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalValues;
        int x = 1;
        while(numRows>0){
            vector<int> pascalRow;
            for(int i=0; i<x; i++){
                if(i==0 || i==x-1){
                    pascalRow.push_back(1);
                }
                else{
                    pascalRow.push_back(pascalValues[pascalValues.size()-1][i-1]+pascalValues[pascalValues.size()-1][i]);
                }
            }
            pascalValues.push_back(pascalRow);
            numRows--;
            x++;
        }
        return pascalValues;
    }
};
// @lc code=end

