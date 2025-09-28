#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) // for each of the node or city
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // dp[v] = length of the longest path from 1 to v (in terms of number of cities).
    // parent[v] = previous node on the best path to reconstruct the route.

    vector<int> dp(n + 1, 0);
    vector<int> parent(n + 1, -1);

    dp[1] = 1;

    for (int u : topo)
    {
        if (dp[u] == 0)
            continue;
        for (int v : adj[u])
        {
            if (dp[u] + 1 > dp[v])
            {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }
    if (dp[n] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[n] << "\n";
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur])
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    for (int city : path)
        cout << city << " ";
    cout << "\n";

    return 0;
}