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
    {
        cin >> a[i];
    }

    vector<long long> freq(n, 0);
    long long prefix = 0;
    freq[0] = 1; // empty prefix remainder 0

    for (int i = 0; i < n; i++)
    {
        prefix += a[i];
        int mod = ((prefix % n) + n) % n; // normalize
        freq[mod]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long cnt = freq[i];
        ans += cnt * (cnt - 1) / 2; // choose 2 with same remainder
    }

    cout << ans << "\n";
    return 0;
}
