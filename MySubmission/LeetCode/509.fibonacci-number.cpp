/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int find_fib(int n, vector<int>& dp){
        if(n==0||n==1)  return n;
        if(dp[n]!=-1)    return dp[n];
        return dp[n] = find_fib(n-1,dp)+find_fib(n-2,dp);
    }
    int fib(int n) {
        if(n==0||n==1)  return n;
        vector<int> dp(n+1,-1);
        return find_fib(n,dp);
    }
};
// @lc code=end

