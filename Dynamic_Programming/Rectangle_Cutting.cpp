#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            int best = 1e9;
            // try all vertical cuts
            //  split into k*j and (i-k)*j
            for (int k = 1; k < i; k++)
            {
                best = min(best, 1 + dp[k][j] + dp[i - k][j]);
            }
            // try all horizontal cuts
            // split into i*k and i*(j-k)
            for (int k = 1; k < j; k++)
            {
                best = min(best, 1 + dp[i][k] + dp[i][j - k]);
            }
            dp[i][j] = best;
        }
    }
    cout << dp[a][b];
    return 0;
}