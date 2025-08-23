#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v[i] = x;
    }
    long long ans = 0;
    for (long long i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1])
            continue;
        else
        {
            ans += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }

    cout << ans << endl;
    return 0;
}