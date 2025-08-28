#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> arr;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    ll ans = 0;
    ll median = arr[n / 2];
    for (auto a : arr)
    {
        ans += abs(a - median);
    }
    cout << ans << "\n";

    return 0;
}