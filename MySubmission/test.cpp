// You are given a 0-indexed m x n binary matrix mat and an integer cols, which denotes the number of columns you must choose.

// A row is covered by a set of columns if each cell in the row that has a value of 1 also lies in one of the columns of the chosen set.

// Return the maximum number of rows that can be covered by a set of cols columns.

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> dp(1<<m,0); // dp[i] = number of rows covered by columns represented by i
        for(int i=0;i<n;i++){ 
            int mask = 0; // mask represents the columns covered by row i
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){ 
                    mask |= (1<<j);
                }
            }
            for(int j=0;j<(1<<m);j++){
                if((j&mask)==mask){ 
                    dp[j] = dp[j] + 1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<(1<<m);i++){
            if(__builtin_popcount(i)==cols){ //no of ones
                ans = max(ans,dp[i]);
            }
        }
        return ans;
    }
};