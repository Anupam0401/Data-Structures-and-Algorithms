#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000007
#define lli long long int
using namespace std;

// Recently, Vlad has been carried away by spanning trees, so his friends, without hesitation, gave him a connected weighted undirected graph of n vertices and m edges for his birthday.

// Vlad defined the ority of a spanning tree as the bitwise OR of all its weights, and now he is interested in what is the minimum possible ority that can be achieved by choosing a certain spanning tree. A spanning tree is a connected subgraph of a given graph that does not contain cycles.

// In other words, you want to keep n−1 edges so that the graph remains connected and the bitwise OR weights of the edges are as small as possible. You have to find the minimum bitwise OR itself.

// Input
// The first line of the input contains an integer t (1<=t<=10^4) — the number of test cases in the input.

// An empty line is written in front of each test case.

// This is followed by two numbers n and m (3<=n<=2⋅10^5,n−1<=m<=2⋅10^5) — the number of vertices and edges of the graph, respectively.

// The next m lines contain the description of the edges. Line i contains three numbers vi, ui and wi (1≤vi,ui≤n, 1≤wi≤109, vi!=ui) — the vertices that the edge connects and its weight.

// It is guaranteed that the sum m and the sum n over all test cases does not exceed 2⋅105 and each test case contains a connected graph.

// Output
// Print t lines, each of which contains the answer to the corresponding set of input data — the minimum possible spanning tree ority.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i = 0; i < m; i++){
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<int> visited(n+1,0);
        vector<int> ans(n+1,0);
        int ans_min = INT_MAX;
        for(int i = 1; i <= n; i++){
            if(visited[i]){
                continue;
            }
            int cur_min = 0;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int j = 0; j < graph[cur].size(); j++){
                    int v = graph[cur][j].first;
                    if(visited[v]){
                        continue;
                    }
                    visited[v] = 1;
                    cur_min += graph[cur][j].second;
                    q.push(v);
                }
            }
            ans_min = min(ans_min,cur_min);
        }
        cout<<ans_min<<endl;
    }
    return 0;
}