#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; // a large value representing "no path"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // Initialize distance matrix
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    // Distance from a city to itself is 0
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    // Read the roads and update direct distances
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        // Since multiple roads can exist, take the minimum
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c); // bidirectional road
    }

    // Floyd-Warshall: compute all-pairs shortest paths
    for (int k = 1; k <= n; k++)
    { // intermediate node
        for (int i = 1; i <= n; i++)
        { // source node
            for (int j = 1; j <= n; j++)
            { // destination node
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Answer the queries
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << "\n"; // no path
        else
            cout << dist[a][b] << "\n"; // shortest path length
    }
    return 0;
}
