#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Item
{
    ll val, idx;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<Item> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].val;
        arr[i].idx = i + 1; // store original 1-based index
    }

    // sort by value
    sort(arr.begin(), arr.end(), [](auto &a, auto &b)
         { return a.val < b.val; });

    // fix one element and do 2-sum with two pointers
    for (int i = 0; i < n; i++)
    {
        ll target = x - arr[i].val;
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            ll sum = arr[l].val + arr[r].val;
            if (sum == target)
            {
                cout << arr[i].idx << " " << arr[l].idx << " " << arr[r].idx << "\n";
                return 0;
            }
            if (sum < target)
                l++;
            else
                r--;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
