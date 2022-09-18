/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution {
public:
    // comparator for sorting
    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        sort(stations.begin(), stations.end(),comp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        
    }
};
// @lc code=end

