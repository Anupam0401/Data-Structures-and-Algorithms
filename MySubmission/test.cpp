
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
// Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].

	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
        vector<vector<int>>adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<int>visited(n,0);
        queue<int>q;
        q.push(s);
        visited[s]=1;
        int count=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr==d)
                return count;
            for(auto &v:adj[curr]){
                if(visited[v]==0){
                    visited[v]=1;
                    q.push(v);
                }
            }
            count++;
        }
        return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends