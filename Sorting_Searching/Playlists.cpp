#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> playlist(n + 1);
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        playlist[i] = a;
    }

    set<ll> seen;
    ll ans = 0, left = 0;

    for (ll right = 0; right < n; right++)
    {
        while (seen.count(playlist[right]))
        {
            seen.erase(playlist[left]);
            left++;
        }
        seen.insert(playlist[right]);
        ans = max(ans, right - left + 1);
    }
    cout << ans << "\n";
    return 0;
}