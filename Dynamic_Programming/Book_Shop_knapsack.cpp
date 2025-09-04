#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    // dp[i][money] = max pages using first i books with at most 'money' money
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int money = 0; money <= x; money++)
        {
            // Option 1: don't take book i
            dp[i][money] = dp[i - 1][money];

            // Option 2: take book i (if possible)
            if (money >= price[i - 1])
            {
                dp[i][money] = max(dp[i][money],
                                   dp[i - 1][money - price[i - 1]] + pages[i - 1]);
            }
        }
    }

    cout << dp[n][x] << "\n";
}
