// Topological sorting for directed acyclic graph using BFS
#include<bits/stdc++.h>
#include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 

class Graph 
{ 
	int V; 

	list<int> *adj; 


	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
	Graph(int V); 
	void addEdge(int v, int w); 

	
	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w);  
} 
 
void Graph::topologicalSortUtil(int v, bool visited[], 
								stack<int> &Stack) 
{ 
	
	visited[v] = true; 

	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			topologicalSortUtil(*i, visited, Stack); 

	Stack.push(v); 
} 


void Graph::topologicalSort() 
{ 
	stack<int> Stack; 

	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 
 
	for (int i = 0; i < V; i++) 
	if (visited[i] == false) 
		topologicalSortUtil(i, visited, Stack); 

	
	while (Stack.empty() == false) 
	{ 
		cout << Stack.top() << " "; 
		Stack.pop(); 
	} 
    cout<<"\n\n";
} 

 
int main() 
{ 
	
	int n,v1,v2;
    cout<<"Enter the number of edges\n";
	cin>>n;
	Graph g(n); 
    cout<<"Enter the "<<n<<" pairs of edges : \n";
    cout<<"NOTE: the vertices are numbered from 0 to n-1\n";
	for(int i=1;i<=n;i++)
    {	
        cin>>v1>>v2;
	    g.addEdge(v1, v2);
    } 
	cout << " Topological Sort of the given graph: \n"; 
	g.topologicalSort(); 
	return 0; 
}