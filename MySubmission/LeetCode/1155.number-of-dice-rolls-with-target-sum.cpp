/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start

// You have n dice and each die has k faces numbered from 1 to k.

// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 10^9 + 7.
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int l=1;l<=k;l++){
                    if(j-l>=0){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-l])%mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};
// @lc code=end

