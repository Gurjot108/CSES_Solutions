#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1; // 1 way to make sum 0

    for (int s = 1; s <= x; s++)
    {
        for (int c : coins)
        {
            if (s - c >= 0)
            {
                dp[s] = (dp[s] + dp[s - c]) % MOD;
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}
