#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Step 1: Precompute prefix sums
    // pref[k] = sum of first k elements (a[0]..a[k-1])
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
    }

    // Helper function: sum of subarray [l..r]
    auto rangeSum = [&](int l, int r)
    {
        return pref[r + 1] - pref[l];
    };

    // Step 2: Create DP table
    /*
    dp[i][j] = maximum score the first player can get
           if the game is played only on a[i..j].

    */
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    // Base case: if subarray has only 1 element,
    // first player just takes it.
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = a[i];
    }

    // Step 3: Fill DP for longer subarrays
    // length = 2, 3, ..., n
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1; // subarray [i..j]

            // Option 1: take left (a[i])
            long long takeLeft = a[i] + (rangeSum(i + 1, j) - dp[i + 1][j]);

            // Option 2: take right (a[j])
            long long takeRight = a[j] + (rangeSum(i, j - 1) - dp[i][j - 1]);

            // First player will choose the better of the two
            dp[i][j] = max(takeLeft, takeRight);
        }
    }

    // Step 4: Answer is best score from whole array
    cout << dp[0][n - 1] << "\n";
    return 0;
}
