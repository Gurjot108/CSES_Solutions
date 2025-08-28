#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> cubes(n + 1);
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        cubes[i] = a;
    }
    multiset<ll> tops;

    for (auto x : cubes)
    {
        auto it = tops.upper_bound(x);
        if (it != tops.end())
        {
            tops.erase(it);
        }
        tops.insert(x);
    }
    cout << tops.size() << "\n";
    return 0;
}