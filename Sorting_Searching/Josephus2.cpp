#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);

    auto it = s.begin();
    vector<int> removal_order;

    while (!s.empty())
    {
        // number of steps to move forward
        long long steps = k % s.size();

        // move iterator 'steps' times, wrap around if necessary
        for (long long i = 0; i < steps; i++)
        {
            it++;
            if (it == s.end())
                it = s.begin();
        }

        removal_order.push_back(*it);
        it = s.erase(it); // erase returns next iterator
        if (it == s.end())
            it = s.begin();
    }

    for (int x : removal_order)
        cout << x << " ";
    return 0;
}
