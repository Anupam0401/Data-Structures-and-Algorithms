/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    // // memoization aaproach
    // int solve(int index, int n, vector<int> &nums, vector<int> &dp){
    //     if(index >= n) return 0;
    //     if(dp[index]!=-1) return dp[index];
    //     int include;
    //     // if(index==0)    include = nums[index] + solve(index+2,--n,nums,dp);
    //     // else include = nums[index] + solve(index+2,n,nums,dp);
    //     include = nums[index] + solve(index+2,n,nums,dp);
    //     int exclude = solve(index+1,n,nums,dp);
    //     return dp[index] = max(include, exclude);
    // }
    // int rob(vector<int>& nums) {
    //     if(nums.size()==1)  return nums[0];
    //     int n=nums.size();
    //     vector<int> dp(nums.size()+1,-1);
    //     int x = solve(1, n, nums, dp);
    //     for(int i=0; i<=n; i++) dp[i] = -1;
    //     int y = solve(0, n-1, nums, dp);
    //     return max(x,y);
    // }
    //doing tabulation and space optimization

    int solve(int n, vector<int> &nums,int a,int b,int p){
        // vector<int> dp(n+1,0);
        // int a=0,b=nums[0];
        // dp[1] = nums[0];
        for(int i=p;i<=n;i++){
            int c = max(b,a+nums[i-1]);
            a=b;
            b=c;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int a = 0,b=nums[1];
        int x = n>=2?solve(n, nums,a,b,3):INT_MIN;
        b=nums[0];
        int y = solve(n-1, nums,a,b,2);
        return max(x,y);
    }
};
// @lc code=end

