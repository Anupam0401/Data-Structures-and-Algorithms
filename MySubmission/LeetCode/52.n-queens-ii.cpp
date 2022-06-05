/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    void solve(int col,int n,int ans,vector<int> &leftRow,vector<int> lowerD, vector<int> upperD){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(leftRow[i]+lowerD[i+col]+upperD[n-1+col-i]==0){
                leftRow[i] = 1;
                lowerD[i+col] = 1;
                upperD[n-1+col-i] = 1;
                // board[i][col] = 'Q';
                solve(col+1,n,ans,board,leftRow,lowerD,upperD);
                leftRow[i] = 0;
                lowerD[i+col] = 0;
                upperD[n-1+col-i] = 0;
                // board[i][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        // vector<string> board(n);
        // string s(n,'.');
        // for(int i=0;i<n;i++)    board[i]=s;
        vector<int> leftRow(n,0);
        vector<int> lowerD(2*n-1,0), upperD(2*n-1,0);
        solve(0,n,ans,leftRow,lowerD,upperD);
        return ans;
    }
};
// @lc code=end

