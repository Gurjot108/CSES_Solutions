#include <bits/stdc++.h>
using namespace std;

void dfs(int index, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[index] = true;
    for (auto u : adj[index])
    {
        if (!visited[u])
        {
            dfs(u, adj, visited);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> representative; // representative of each component
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            representative.push_back(i);
            dfs(i, adj, visited);
        }
    }

    // Number of components
    cout << representative.size() - 1 << "\n";

    // Connect components
    for (int i = 0; i < representative.size() - 1; i++)
    {
        cout << representative[i] << " " << representative[i + 1] << "\n";
    }

    return 0;
}
