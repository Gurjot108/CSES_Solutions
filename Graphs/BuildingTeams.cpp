#include <bits/stdc++.h>
using namespace std;

vector<int> team;
vector<vector<int>> adj;
bool possible = true;

void dfs(int v, int t)
{
    team[v] = t;
    for (auto u : adj[v])
    {
        if (team[u] == 0)
            dfs(u, 3 - t);
        else if (team[u] == t)
            possible = false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    team.assign(n + 1, 0);
    adj.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (team[i] == 0)
            dfs(i, 1);
    }

    if (!possible)
        cout << "IMPOSSIBLE\n";
    else
    {
        for (int i = 1; i <= n; i++)
            cout << team[i] << " ";
        cout << "\n";
    }

    return 0;
}
