#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<ll> survivor(n + 1, 0);
    // f(1) = 0 by definition
    for (ll i = 2; i <= n; i++)
    {
        survivor[i] = (survivor[i - 1] + k) % i;
    }

    // print survivors for each size (1-based person number)
    for (int i = 1; i <= n; i++)
    {
        cout << survivor[i] + 1 << " ";
    }
    return 0;
}
