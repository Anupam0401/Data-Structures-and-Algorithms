/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution {
public:
    int solve(int index, int fuel, int target, int fuel, vector<vector<int>> &stations){
        if(index==stations.size()){
            return fuel>=target?0:INT_MAX;
        }
    }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //recursive solution
        solve(0,target,startFuel,stations);                                                       
    }
};
// @lc code=end

