/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; i++) {
            dp[i][src] = 0;
            for (auto &flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                if (dp[i - 1][from] != INT_MAX) {
                    dp[i][to] = min(dp[i][to], dp[i - 1][from] + price);
                }
            }
        }
        return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
    }
};
// @lc code=end

