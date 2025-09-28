#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
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
    for (int i = 1; i <= n; i++)
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

    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for (int u : topo)
    {
        for (int v : adj[u])
        {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }
    cout << dp[n] % MOD << "\n";

    return 0;
}