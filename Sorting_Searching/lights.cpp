#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, n;
    cin >> x >> n; // first street length, then number of lights
    vector<ll> pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }

    set<ll> lights{0, x};
    multiset<ll> lengths = {x};

    for (auto p : pos)
    {
        auto it = lights.upper_bound(p); // find right neighbor
        ll r = *it;
        ll l = *prev(it);

        lengths.erase(lengths.find(r - l)); // remove old segment
        lengths.insert(r - p);              // add new segment
        lengths.insert(p - l);

        lights.insert(p); // insert new light

        cout << *lengths.rbegin() << " "; // largest segment
    }

    return 0;
}
