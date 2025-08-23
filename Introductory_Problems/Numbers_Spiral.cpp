#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    for (long long k = 1; k <= n; k++)
    {
        long long total = k * k * (k * k - 1) / 2;
        long long sum = 4 * (k - 1) * (k - 2);
        long long ans = total - sum;
        cout << ans << endl;
    }
    return 0;
}