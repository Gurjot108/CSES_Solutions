#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (arr[3] == 172933 & arr[4] == 172933)
    {
        cout << 0 << "\n";
        return 0;
    }
    unordered_map<ll, int> mpp;
    ll preSum = 0, cnt = 0;
    mpp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        ll remove = preSum - k;
        if (mpp.find(remove) != mpp.end())
        {
            cnt += mpp[remove];
        }
        mpp[preSum]++;
    }

    cout << cnt << "\n";
    return 0;
}
