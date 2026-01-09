#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    return 0;
}