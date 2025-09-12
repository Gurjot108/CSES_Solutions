#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> count(n + 1, 0); // how many times each node was popped
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    pq.push({0, 1}); // distance 0, start at node 1

    vector<long long> ans;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (count[u] >= k)
            continue;
        count[u]++;

        if (u == n)
        {
            ans.push_back(d);
            if ((int)ans.size() == k)
                break; // got k answers
        }

        for (auto [v, w] : adj[u])
        {
            pq.push({d + w, v});
        }
    }

    for (long long x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
