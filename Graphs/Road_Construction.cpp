#include <bits/stdc++.h>
using namespace std;
struct DSU
{
    vector<int> parent, size;

    void init(int n)
    {
        parent.assign(n + 1, 0);
        size.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i; // each node is its own root
    }

    int find(int u)
    {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false; // already same component

        // union by size: attach smaller to bigger
        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
        return true; // merge successful
    }

    int component_size(int u)
    {
        return size[find(u)];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu;
    dsu.init(n);

    int components = n;
    int max_size = 1;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        if (dsu.unite(a, b))
        {
            components--;
            max_size = max(max_size, dsu.component_size(a));
        }

        cout << components << " " << max_size << "\n";
    }

    return 0;
}
