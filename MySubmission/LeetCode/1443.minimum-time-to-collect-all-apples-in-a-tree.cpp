/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start

// Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

// The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        dfs(0, -1, adj, hasApple, ans);
        return ans;
    }

private:
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<bool>& hasApple, int& ans) {
        for (auto v : adj[u]) {
            if (v == parent) continue;
            dfs(v, u, adj, hasApple, ans);
            if (hasApple[v]) {
                ans += 2;
                hasApple[u] = true;
            }
        }
    }
};

// @lc code=end

