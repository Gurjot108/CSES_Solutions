#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17;

struct Edge
{
    int u, v;
    long long weight;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    // --- Start of Changes ---

    // Step 1: Run n-1 relaxation iterations
    // This finds the shortest paths if no negative cycles exist.
    for (int i = 0; i < n - 1; ++i)
    {
        for (const auto &edge : edges)
        {
            if (dist[edge.u] + edge.weight < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight;
                parent[edge.v] = edge.u;
            }
        }
    }

    // Step 2: Run the n-th iteration for detection
    // If any distance can still be improved, a negative cycle is present.
    int cycle_node = -1;
    for (const auto &edge : edges)
    {
        if (dist[edge.u] + edge.weight < dist[edge.v])
        {
            // A shorter path was found, indicating a negative cycle
            dist[edge.v] = dist[edge.u] + edge.weight; // Update for correct path reconstruction
            parent[edge.v] = edge.u;
            cycle_node = edge.v;
            // Since we only need to report one cycle, we can break after finding the first evidence of one.
            break;
        }
    }

    // --- End of Changes ---

    if (cycle_node == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";

        int start_of_cycle = cycle_node;
        for (int i = 0; i < n; ++i)
        {
            start_of_cycle = parent[start_of_cycle];
        }

        // --- Simplified Cycle Reconstruction and Printing ---

        // Step 1: Reconstruct the cycle using a do-while loop
        vector<int> cycle_path;
        int current = start_of_cycle;
        do
        {
            cycle_path.push_back(current);
            current = parent[current];
        } while (current != start_of_cycle);
        cycle_path.push_back(start_of_cycle);

        // The path was constructed backwards, so reverse it.
        reverse(cycle_path.begin(), cycle_path.end());

        // Step 2: Print the path using the separator trick
        const char *sep = "";
        for (int node : cycle_path)
        {
            cout << sep << node;
            sep = " ";
        }
        cout << "\n";
    }

    return 0;
}