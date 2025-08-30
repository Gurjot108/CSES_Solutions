#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; // infinity
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1); // adjacency list: (neighbor, weight)
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    // min-heap: (distance, node)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue; // skip outdated entries

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // print distances
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << ' ';
    }
    return 0;
}
