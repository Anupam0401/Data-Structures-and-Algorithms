/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int solve(vector<int>& cardPoints,int left, int right, int sum, int k){
        if(k<=0)    return sum;
        int ls = solve(cardPoints, left+1,right,sum+cardPoints[left],k-1);
        int rs = solve(cardPoints, left, right-1,sum+cardPoints[right],k-1);
        return max(ls, rs);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        return solve(cardPoints,0,n-1,0,k);
    }
};
// @lc code=end

