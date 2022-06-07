// Problem Statement
// There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

#include <bits/stdc++.h>
// int solve(int ind, vector<int> &heights,vector<int> &dp){
    
//     if(ind==0)    return 0;
//     if(dp[ind]!=-1)    return dp[ind];
//     int left = solve(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
//     int right = INT_MAX;
//     if(ind>1)
//         right = solve(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
//     return dp[ind] = min(left,right);
// }

int frogJump(int n, vector<int> &heights)
{
//     int ans=0;
    vector<int> dp(n,-1);
    dp[0]=0;
    dp[1] = abs(heights[0]-heights[1]);
    for(int i=2;i<n;i++){
        dp[i] = min(dp[i-1]+abs(heights[i-1]-heights[i]),dp[i-2]+abs(heights[i-2]-heights[i]));
    }
    return dp[n-1];
}
