#include <bits/stdc++.h>
using namespace std;

// Structure to store project info
struct Project
{
    long long start, end, reward;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Project> projects(n);
    for (int i = 0; i < n; i++)
    {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    // Step 1: Sort projects by ending day
    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b)
         { return a.end < b.end; });

    // dp[i] = max money we can get using first i projects
    vector<long long> dp(n);
    // ends[i] = ending day of i-th project, used for binary search
    vector<long long> ends(n);
    for (int i = 0; i < n; i++)
        ends[i] = projects[i].end;

    for (int i = 0; i < n; i++)
    {
        // Option 1: take the current project
        long long take = projects[i].reward;

        // Find the last project that ends BEFORE current project starts
        int idx = upper_bound(ends.begin(), ends.end(), projects[i].start - 1) - ends.begin() - 1;

        if (idx >= 0)
        {
            take += dp[idx]; // add max reward from previous compatible project
        }

        // Option 2: skip the current project
        long long skip = 0;
        if (i > 0)
        {
            skip = dp[i - 1]; // max reward without taking current project
        }

        // Choose the better option
        dp[i] = max(take, skip);
    }

    cout << dp[n - 1] << "\n"; // answer: max money we can earn

    return 0;
}
