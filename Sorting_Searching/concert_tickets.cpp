#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    multiset<ll> ticket_price;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ticket_price.insert(x);
    }
    for (ll i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = ticket_price.upper_bound(x);
        if (it == ticket_price.begin())
        {
            cout << "-1" << "\n";
        }
        else
        {
            --it;
            cout << *it << "\n";

            ticket_price.erase(it);
        }
    }

    return 0;
}