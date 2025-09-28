#include <bits/stdc++.h>
using namespace std;

// Problem: Find a round trip in a directed graph (cycle with distinct nodes)

// Number of nodes and edges
int n, m;

// Adjacency list of the graph (graph[u] stores all neighbors v such that u -> v)
vector<vector<int>> graph;

// state[u]: 0 = unvisited, 1 = active (in recursion stack), 2 = finished
vector<int> state;

// parent[u] is used to reconstruct the cycle path when a back edge is found
vector<int> parent;

// Stores the cycle (round trip) once found
vector<int> cycle;

// DFS function to detect a cycle
bool dfs(int u)
{
    state[u] = 1; // mark node as active (in recursion stack)
    for (int v : graph[u])
    {
        if (state[v] == 0)
        {                  // if neighbor is unvisited
            parent[v] = u; // record the parent to reconstruct the path later
            if (dfs(v))
                return true; // if cycle found in DFS subtree, propagate true
        }
        else if (state[v] == 1)
        { // back edge found → cycle detected
            // Reconstruct the cycle using parent array
            cycle.push_back(v);
            int cur = u;
            while (cur != v)
            {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end()); // order: start -> ... -> start
            return true;                         // cycle found
        }
    }
    state[u] = 2; // mark node as finished
    return false; // no cycle found from this node
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // Initialize adjacency list and helper arrays
    graph.assign(n + 1, vector<int>()); // 1-based indexing
    state.assign(n + 1, 0);             // initially all nodes unvisited
    parent.assign(n + 1, -1);           // parent of each node (for cycle reconstruction)

    // Read edges and build the graph
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    bool found = false;
    // Try DFS from every unvisited node (to handle disconnected components)
    for (int i = 1; i <= n; i++)
    {
        if (state[i] == 0)
        {
            if (dfs(i))
            { // cycle found
                found = true;
                break;
            }
        }
    }

    // Output the result
    if (!found)
    {
        cout << "IMPOSSIBLE\n"; // no cycle exists
    }
    else
    {
        cout << cycle.size() << "\n"; // number of cities in round trip
        for (int x : cycle)
            cout << x << " "; // print the round trip path
        cout << "\n";
    }

    return 0;
}
