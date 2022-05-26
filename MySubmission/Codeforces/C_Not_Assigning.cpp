#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;

// You are given a tree of n vertices numbered from 1 to n, with edges numbered from 1 to n−1. A tree is a connected undirected graph without cycles. You have to assign integer weights to each edge of the tree, such that the resultant graph is a prime tree.

// A prime tree is a tree where the weight of every path consisting of one or two edges is prime. A path should not visit any vertex twice. The weight of a path is the sum of edge weights on that path.

// Consider the graph below. It is a prime tree as the weight of every path of two or less edges is prime. For example, the following path of two edges: 2→1→3 has a weight of 11+2=13, which is prime. Similarly, the path of one edge: 4→3 has a weight of 5, which is also prime.


// Print any valid assignment of weights such that the resultant tree is a prime tree. If there is no such assignment, then print −1. It can be proven that if a valid assignment exists, one exists with weights between 1 and 105 as well.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        // declare the tree with n-1 edges
        vector<vector<int>> tree(n, vector<int>(n, 0));
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n-1; j++)
            {
                cin>>tree[i][j];
            }
        }
    }
    return 0;
}
