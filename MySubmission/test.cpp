// You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

// You are also given a string s of length n, where s[i] is the character assigned to node i.

// Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.


class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[parent[i]].push_back(i);
        }
        vector<int> visited(n, 0);
        vector<int> dp(n, 0);
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                maxLen = max(maxLen, dfs(graph, s, i, visited));
            }
        }
        return maxLen;
    }
    int dfs(vector<vector<int>>& graph, string& s, int node, vector<int>& visited) {
        visited[node] = 1;
        int maxLen = 0;
        for (auto& child : graph[node]) {
            if (visited[child] == 0) {
                int childLen = dfs(graph, s, child, visited);
                if (s[node] != s[child]) {
                    maxLen = max(maxLen, childLen + 1);
                }
            }
        }
        return maxLen;
    }
};