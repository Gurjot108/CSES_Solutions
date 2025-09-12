#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> disc, low, comp, stk; // disc is the discovery time, low is the lowest time, stk is the stack, comp is the component array

// comp[u] = which SCC  node u belongs to
// eg comp[1] = comp[2] = comp[3] = 1

vector<char> inStack; // to check if the node is in the stack

int timer = 0, scc_count = 0;
// timer is the global time, scc count

void tarjan(int u)
{
    // step 1 assign the discovery and low to the u node and push in stack
    disc[u] = low[u] = ++timer; // imp to note
    stk.push_back(u);
    inStack[u] = 1;

    for (int v : adj[u])
    {
        // this is for going in the dfs cave
        if (!disc[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }

        // when we retrace back the path
        else if (inStack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    // we have found an scc
    if (low[u] == disc[u])
    {
        ++scc_count;
        while (true)
        {
            // we assign the scc id to all the components till u ie the root
            int v = stk.back();
            stk.pop_back();
            inStack[v] = 0;
            comp[v] = scc_count;
            if (v == u)
                break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    disc.assign(n + 1, 0);
    low.assign(n + 1, 0);
    comp.assign(n + 1, 0);
    inStack.assign(n + 1, 0);

    // now for each node we run the tarjan if the discovery time is 0

    // nodes start from 1 and go to n
    for (int i = 1; i <= n; i++)
    {
        if (!disc[i])
            tarjan(i);
    }

    if (scc_count == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
        // pick two nodes in different SCCs
        int x = 1, y = -1;
        for (int i = 2; i <= n; i++)
        {
            if (comp[i] != comp[x])
            {
                y = i;
                break;
            }
        }
        // decide which way fails
        if (comp[x] < comp[y])
            cout << x << " " << y << "\n";
        else
            cout << y << " " << x << "\n";
    }

    return 0;
}