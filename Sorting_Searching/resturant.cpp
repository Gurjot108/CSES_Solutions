#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    vector<pair<ll, int>> events;
    // (time, +1 for arrival / -1 for departure)

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        events.push_back({a, +1}); // arrival
        events.push_back({b, -1}); // departure
    }

    // sort by time; if tie -> departure (-1) before arrival (+1)
    sort(events.begin(), events.end(), [](const pair<ll, int> &x, const pair<ll, int> &y)
         {
        if (x.first == y.first) return x.second < y.second; 
        return x.first < y.first; });

    // up to here, events are correctly prepared and sorted.
    // next: sweep line to count maximum customers
    int count = 0, maxcount = 0;
    for (auto e : events)
    {
        count += e.second;
        maxcount = max(maxcount, count);
    }
    cout << maxcount;
    return 0;
}
