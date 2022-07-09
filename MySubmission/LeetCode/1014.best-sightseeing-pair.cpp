/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxScore = INT_MIN,maxTillNow = values[0];
        for(int i=1;i<n;i++){
            maxScore = max(maxScore,--maxTillNow+values[i]);
            maxTillNow = max(maxTillNow,values[i]);
        }
        return maxScore;
    }
};
// @lc code=end

