// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

class graph
{

public:
    // Add edge
    void addEdge(vector<int> adj[], int u, int v, bool direction)
    {
        // direction=0->undirected
        // direction=1->directed
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // Print the graph
    void printGraph(vector<int> adj[], int m)
    {
        for (int v = 0; v < m; ++v)
        {
            cout << "\n Vertex " << v << ":";
            for (auto x : adj[v])
                cout << "-> " << x;
            printf("\n");
        }
    }

    void adjacencylist(vector<int> adj[], int m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << i << "->";
            for (int &x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "enter the number of nodes";
    cin >> n;
    cout << "\n enter the number of edges";
    cin >> m;
    vector<int> adj[n + 1];
    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(adj, u, v, 0);
    }

    g.adjacencylist(adj, m);
    return 0;
}