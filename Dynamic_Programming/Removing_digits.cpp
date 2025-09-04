#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    const int inf = 1e9;
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int x = 0; x <= n; x++)
    {
        int temp = x;
        while (temp > 0)
        {
            int d = temp % 10;
            if (d != 0)
            {
                dp[x] = min(dp[x], 1 + dp[x - d]);
            }
            temp = temp / 10;
        }
    }
    cout << dp[n];

    return 0;
}