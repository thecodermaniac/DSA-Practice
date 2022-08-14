#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int vertices, vector<int> adj[])
{
    vector<int> visited(vertices + 1, 0);
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            queue<int> que;
            que.push(i);
            visited[i] = 1;
            while (!que.empty())
            {
                int node = que.front();
                cout << node;
                que.pop();

                for (auto &it : adj[node])
                {
                    if (!visited[it])
                    {
                        que.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cout << "no of vertices and edges:";
    cin >> n >> m;
    vector<int> adj[n + 1];
    cout << "enter the edges ";
    for (int i = 0; i < m; i++)
    {
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
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
    bfs(n, adj);
    return 0;
}
