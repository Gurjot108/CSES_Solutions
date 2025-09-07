#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm> // For std::min

// Using a large constant for infinity is a good practice.
// The maximum possible path cost can exceed a 32-bit integer, so we use long long.
const long long INF = 1e18;

using namespace std;

// Using a type alias for graph edges can make the code cleaner.
// It stores {neighbor_city, flight_price}.
using Edge = pair<int, int>;

int main()
{
    // Fast I/O is helpful in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // An adjacency list is the most efficient graph representation for Dijkstra's.
    // adj[u] will store a vector of all flights departing from city u.
    vector<vector<Edge>> adj(n + 1);

    // Read all the flights and build the adjacency list.
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Your priority queue is set up correctly.
    // We store {cost, city, coupon_state}, where coupon_state is 0 or 1.
    // Note: The cost should be long long to avoid overflow.
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

    // Distance array: dist[city][coupon_state]
    // dist[i][0] = cheapest cost to city i WITHOUT using the coupon.
    // dist[i][1] = cheapest cost to city i AFTER using the coupon.
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));

    // --- Start of Dijkstra's Algorithm ---

    // 1. Initialize the starting state.
    // We start at city 1 with a cost of 0 and the coupon available.
    dist[1][0] = 0;
    pq.push({0, 1, 0}); // {cost, city, coupon_not_used}

    // 2. Process the queue until it's empty.
    while (!pq.empty())
    {
        // Get the state with the smallest cost from the queue.
        auto [d, u, coupon_used] = pq.top();
        pq.pop();

        // Optimization: if we've already found a better path to this state, skip.
        if (d > dist[u][coupon_used])
        {
            continue;
        }

        // 3. Explore all outgoing flights from the current city 'u'.
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            // --- Scenario 1: We arrived at 'u' and still have our coupon ---
            if (coupon_used == 0)
            {
                // Option A: Fly to 'v' without using the coupon.
                if (dist[u][0] + weight < dist[v][0])
                {
                    dist[v][0] = dist[u][0] + weight;
                    pq.push({dist[v][0], v, 0});
                }

                // Option B: Fly to 'v' and USE the coupon.
                if (dist[u][0] + (weight / 2) < dist[v][1])
                {
                    dist[v][1] = dist[u][0] + (weight / 2);
                    pq.push({dist[v][1], v, 1});
                }
            }
            // --- Scenario 2: We arrived at 'u' and have already used our coupon ---
            else
            { // coupon_used == 1
                // We have no choice but to pay the full price.
                if (dist[u][1] + weight < dist[v][1])
                {
                    dist[v][1] = dist[u][1] + weight;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    // 4. The final answer is the minimum cost to reach the destination city 'n'.
    cout << min(dist[n][0], dist[n][1]) << endl;

    return 0;
}