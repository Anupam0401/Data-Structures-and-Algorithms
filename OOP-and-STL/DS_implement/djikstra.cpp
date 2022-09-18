#include<iostream>
using namespace std;

// implement djikstra's algorithm

class Graph
{
private:
    int V;
    int **adj;
    int *dist;
    bool *visited;
    int minDistance()
    {
        int min = INT_MAX;
        int min_index;
        for(int i=0; i<V; i++)
        {
            if(!visited[i] && dist[i] <= min)
            {
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }
public:
    Graph(int V)
    {
        this->V = V;
        adj = new int*[V];
        for(int i=0; i<V; i++)
        {
            adj[i] = new int[V];
        }
        dist = new int[V];
        visited = new bool[V];
    }
    void addEdge(int u, int v, int w)
    {
        adj[u][v] = w;
        adj[v][u] = w;
    }
    void dijkstra(int src)
    {
        for(int i=0; i<V; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
        }
        dist[src] = 0;
        for(int i=0; i<V-1; i++)
        {
            int u = minDistance();
            visited[u] = true;
            for(int v=0; v<V; v++)
            {
                if(!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u]+adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
        for(int i=0; i<V; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.dijkstra(0);
    return 0;
}
