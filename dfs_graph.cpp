#include <iostream>
#include <vector>

using namespace std;

void dfs(int vertex, vector<int> &visited, vector<int> adj[])
{
    cout << vertex;
    visited[vertex] = 1;
    for (auto &it : adj[vertex])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj);
        }
    }
}
void dfsOfGraph(int vertices, vector<int> adj[])
{
    vector<int> visited(vertices + 1, 0);
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj);
        }
    }
}

int main()
{
    int n, m;
    cout << "enter the vertices and edges:";
    cin >> n >> m;
    vector<int> adj[n + 1];
    cout << "enter the edges: ";
    for (int i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    int i = 1;
    while (i <= n)
    {
        cout << i << "->";
        for (auto &it : adj[i])
        {
            cout << it << " ";
        }
        i++;
        cout << endl;
    }
    dfsOfGraph(n, adj);
}