#include <bits/stdc++.h>
using namespace std;

// Adjacency list to store subordinates of each employee
vector<vector<int>> sub;
// Array to store the total number of subordinates for each employee
vector<int> subordinate_count;

// DFS function to count subordinates for employee u
int dfs(int u)
{
    int cnt = 0; // count of subordinates
    for (int v : sub[u])
    {
        cnt += 1 + dfs(v); // 1 for the direct subordinate + all subordinates of v
    }
    subordinate_count[u] = cnt; // store the total count for employee u
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // number of employees

    vector<int> boss(n + 1); // boss[i] = boss of employee i
    boss[1] = 0;             // employee 1 is the general director, has no boss

    for (int i = 2; i <= n; i++)
    {
        cin >> boss[i]; // read the boss of employee i
    }

    // Initialize adjacency list and subordinate_count array
    sub.resize(n + 1);
    subordinate_count.resize(n + 1);

    // Build the hierarchy tree
    for (int i = 2; i <= n; i++)
    {
        sub[boss[i]].push_back(i); // boss[i] has employee i as a subordinate
    }

    // Run DFS starting from the general director (employee 1)
    dfs(1);

    // Print the number of subordinates for each employee
    for (int i = 1; i <= n; i++)
    {
        cout << subordinate_count[i] << " ";
    }
    cout << "\n";

    return 0;
}
