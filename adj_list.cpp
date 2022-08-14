#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> adj[6];
    cout << "enter the edges ";
    for (int i = 0; i < 7; i++)
    {
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }
    int i = 0;
    while (i < 7)
    {
        for (auto &it : adj[i])
        {
            cout << it << " ";
        }
        i++;
        cout << endl;
    }
    return 0;
}