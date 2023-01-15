/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start

// You are given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0, and each node of the tree has a label which is a lower-case character given in the string labels (i.e. The node with the number i has the label labels[i]).

// The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

// Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

// A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n, 0);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        dfs(graph, labels, 0, visited, ans);
        return ans;
    }
    vector<int> dfs(vector<vector<int>>& graph, string& labels, int node, vector<int>& visited, vector<int>& ans) {
        visited[node] = 1;
        vector<int> count(26, 0);
        count[labels[node] - 'a']++;
        for (auto& child : graph[node]) {
            if (visited[child] == 0) {
                vector<int> childCount = dfs(graph, labels, child, visited, ans);
                for (int i = 0; i < 26; i++) {
                    count[i] += childCount[i];
                }
            }
        }
        ans[node] = count[labels[node] - 'a'];
        return count;
    }
    
};
// @lc code=end

