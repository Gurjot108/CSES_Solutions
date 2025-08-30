#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long sum = 0, maxi = 0;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        maxi = max(maxi, arr[i]);
    }
    long long ans = max(maxi * 2, sum);
    cout << ans;
    return 0;
}
