#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // adjacency list: adj[u] = list of (v, cost) flights from u
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[v] = minimum cost from 1 to v
    vector<ll> dist(n + 1, INF);

    // ways[v] = number of shortest paths from 1 to v (mod MOD)
    vector<ll> ways(n + 1, 0);

    // minFlights[v] = minimum flights (edges) among shortest paths to v
    // maxFlights[v] = maximum flights among shortest paths to v
    vector<int> minFlights(n + 1, INT_MAX);
    vector<int> maxFlights(n + 1, 0);

    // priority queue for Dijkstra (min-heap by distance)
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    // Initialize start city (1 = Syrjälä)
    dist[1] = 0;
    ways[1] = 1;       // one way to be at start
    minFlights[1] = 0; // zero flights taken
    maxFlights[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue; // ignore outdated entries

        // Relax all outgoing flights from u
        for (auto [v, w] : adj[u])
        {
            ll nd = d + w; // new distance if we go u -> v

            if (nd < dist[v])
            {
                // Found a strictly cheaper route to v
                dist[v] = nd;

                // All shortest paths to v now come from u
                ways[v] = ways[u];

                // Flights count updated (since we extended from u)
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;

                pq.push({dist[v], v});
            }
            else if (nd == dist[v])
            {
                // Found another shortest path to v (same cost)

                // Add to number of ways
                ways[v] = (ways[v] + ways[u]) % MOD;

                // Among all shortest paths to v, take min flights
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);

                // And also track max flights
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }

    // Print results for city n (Lehmälä):
    // 1) minimum price
    // 2) number of such routes
    // 3) min flights among them
    // 4) max flights among them
    cout << dist[n] << " " << (ways[n] % MOD) << " "
         << minFlights[n] << " " << maxFlights[n] << "\n";

    return 0;
}
