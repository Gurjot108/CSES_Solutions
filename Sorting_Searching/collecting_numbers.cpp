#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> position(n + 1);
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        position[a] = i;
    }

    ll rounds = 1;
    for (int i = 2; i <= n; i++)
    {
        if (position[i] < position[i - 1])
            rounds++;
    }
    cout << rounds << "\n";
    return 0;
