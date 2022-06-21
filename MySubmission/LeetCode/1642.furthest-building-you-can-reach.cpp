/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

// You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

// While moving from building i to building i+1 (0-indexed),

// If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

// @lc code=start
class Solution {
public:
    int solve(int ind, int count, vector<int> &heights, int bricks, int ladders, vector<vector<int>> &dp)
    {
        if (ladders < 0 || bricks < 0)
        {
            return count-1;
        }
        if (ind == heights.size() - 1)
        {
            return count;
        }
        if (heights[ind + 1] <= heights[ind])
        {
            return solve(ind + 1, count + 1, heights, bricks, ladders, dp);
        }
        else
        {
            int bricks_needed = heights[ind + 1] - heights[ind];
            int useBricks = solve(ind + 1, count + 1, heights, bricks - bricks_needed, ladders, dp);
            if(dp[ind][ladders]!=-1)
                return max(dp[ind][ladders],useBricks);
            dp[ind][ladders] = solve(ind + 1, count + 1, heights, bricks, ladders - 1, dp);
            return max(useBricks, dp[ind][ladders]);
        }
    }
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        // trying out recursive approach
        int n = heights.size();
        vector<vector<int>> dp(n+1, vector<int>(ladders+1, -1));
        return solve(0, 0, heights, bricks, ladders, dp);
    }
};
// @lc code=end

