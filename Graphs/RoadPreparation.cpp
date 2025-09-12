#include <bits/stdc++.h>
using namespace std;

// -------- DSU (Disjoint Set Union / Union-Find) --------
struct DSU
{
    vector<int> parent, size;

    // initialize DSU with n elements
    void init(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    // find the representative (leader) of a set
    int find(int u)
    {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    // unite two sets, returns true if union happened
    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false; // already in same component → adding this edge makes cycle

        // union by size (attach smaller tree to bigger tree)
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return true;
    }
};

// -------- Edge representation --------
struct Edge
{
    int u, v, w; // edge between u and v with weight w
};

// comparator for sorting edges by weight
bool cmp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; // n = nodes, m = edges

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Step 1: Sort all edges by weight
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu;
    dsu.init(n);

    long long total = 0; // total cost of MST
    int cnt = 0;         // number of edges used in MST

    // Step 2: Process edges in sorted order
    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {                 // if edge connects two different components
            total += e.w; // add its cost
            cnt++;        // increase MST edge count
        }
    }

    // Step 3: Check if MST exists
    if (cnt == n - 1)
        cout << total << "\n"; // valid MST
    else
        cout << "IMPOSSIBLE\n"; // graph not connected
    return 0;
}
