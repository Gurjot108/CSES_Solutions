#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj; // our adjancency list
vector<int> cycle;       // the cycle we are storing
vector<int> parent;      // store the parent of the each node
vector<bool> visited;    // check if the node was visited earlier

bool dfs(int v, int par)
{
    visited[v] = true;
    parent[v] = par;

    for (int u : adj[v])
    {
        if (u == par)
            continue;   // skip to the next element in the adj list as we dont check for the parent
        if (visited[u]) // if the cycle is found
        {
            cycle.push_back(u);
            int curr = v;
            while (curr != u)
            {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(u);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
        else
        {
            if (dfs(u, v))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    parent.assign(n + 1, -1);
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i, -1))
        {
            cout << cycle.size() << "\n";
            for (int x : cycle)
                cout << x << " ";
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}