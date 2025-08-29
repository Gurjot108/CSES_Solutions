#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<pair<ll, ll>> st;
    vector<ll> ans(n);

    for (ll i = 0; i < n; i++)
    {
        // Pop all elements >= current
        while (!st.empty() && st.top().first >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
            ans[i] = 0; // no smaller element to the left
        else
            ans[i] = st.top().second; // nearest smaller index (1-based)

        st.push({arr[i], i + 1}); // store value and 1-based index
    }

    for (ll x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
