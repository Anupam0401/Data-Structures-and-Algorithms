/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int m= points.size(), n = points[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        # initialize a  priority queue
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<m; i++)
            pq.push({0,i});
        while(!pq.empty()){
            auto [cost, idx] = pq.top();
            pq.pop();
            for(int i=0; i<m; i++){
                if(i == idx)
                    continue;
                int d = abs(points[idx][0]-points[i][0]) + abs(points[idx][1]-points[i][1]);
                if(dp[idx][0] + d < dp[i][0]){
                    dp[i][0] = dp[idx][0] + d;
                    pq.push({dp[i][0], i});
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

