#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // n is computer and m is connection

    // make the adjancency list first
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n + 1, -1); // parent of each node we would store here
    vector<int> dist(n + 1, -1);   // we store the distance of each node from the 1 node here
    queue<int> q;
    dist[1] = 0; // as we start the search from 1 we make its distance as 0
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto neighbor : adj[node])
        {
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    if (dist[n] == -1)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

    vector<int> path;
    int cur = n; // start from the target node
    while (cur != -1)
    { // until we reach the start node's parent (-1)
        path.push_back(cur);
        cur = parent[cur]; // move to the node we came from
    }
    reverse(path.begin(), path.end()); // reverse to get path from 1 to n

    cout << path.size() << "\n";
    for (int node : path)
    {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}