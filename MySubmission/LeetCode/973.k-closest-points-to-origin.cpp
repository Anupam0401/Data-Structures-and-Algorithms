/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x+y*y;
            pq.push({dis,i});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

