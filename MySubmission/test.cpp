// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

// You are also given two integers node1 and node2.

// Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

// Note that edges may contain cycles.

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> adj[edges.size()];
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1) adj[edges[i]].push_back(i);
        }
        queue<int> q;
        q.push(node1);
        q.push(node2);
        int dist[edges.size()];
        memset(dist,0x3f,sizeof(dist));
        dist[node1] = 0;
        dist[node2] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=0;i<adj[cur].size();i++){
                if(dist[adj[cur][i]]==0x3f){
                    dist[adj[cur][i]] = dist[cur]+1;
                    q.push(adj[cur][i]);
                }
            }
        }
        int ans = 0x3f;
        for(int i=0;i<edges.size();i++){
            if(dist[i]!=0x3f) ans = min(ans,dist[i]);
        }
        if(ans==0x3f) return -1;
        else return ans;
    }
    
};