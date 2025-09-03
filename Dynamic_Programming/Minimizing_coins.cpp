#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: number of coins (n) and target sum (x)
    int n, x;
    cin >> n >> x;

    // Read the available coin values
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // We'll use dynamic programming:
    // dp[s] = minimum number of coins needed to form sum "s"
    const int INF = 1e9; // a large value meaning "impossible"
    vector<int> dp(x + 1, INF);

    // Base case: sum 0 can be formed with 0 coins
    dp[0] = 0;

    // Fill dp for all sums from 1 to x
    for (int s = 1; s <= x; s++)
    {
        // Try using each coin
        for (int c : coins)
        {
            if (s - c >= 0)
            {
                // If we can make sum (s - c), then try adding coin "c"
                dp[s] = min(dp[s], dp[s - c] + 1);
            }
        }
    }

    // If dp[x] is still INF, it means sum x is impossible
    if (dp[x] == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dp[x] << "\n";
    }
    return 0;
}
