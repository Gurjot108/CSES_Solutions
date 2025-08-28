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
    ll ans = INT_MIN;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum < 0)
        {
            sum = 0;
        }
        sum += arr[i];
        ans = max(sum, ans);
    }
    cout << ans << "\n";

    return 0;
}
