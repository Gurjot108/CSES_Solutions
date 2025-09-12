#include <bits/stdc++.h>
using namespace std;

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
    vector<int> topo; // push back karaenge na isliye nhi initiialse karenge
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        topo.push_back(a);

        for (int x : adj[a])
        {

            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }

    if (topo.size() != n)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int x : topo)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}