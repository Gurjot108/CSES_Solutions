#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;

    long long S = 1LL * n * (n + 1) / 2;

    if (S % 2 != 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    int target = S / 2;
    // we need one subset with this sum

    // dp[s] equals numberof ways to form sum s
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= n; num++)
    {
        for (int s = target; s >= num; s--)
        {
            dp[s] = (dp[s] + dp[s - num]) % MOD;
        }
    }
    // Step 4: dp[target] counts subsets with sum = target
    long long ways = dp[target];

    // Each partition is counted twice (A vs B), so divide by 2
    long long inv2 = (MOD + 1) / 2;
    long long answer = (ways * inv2) % MOD;

    cout << answer << "\n";
    return 0;
}