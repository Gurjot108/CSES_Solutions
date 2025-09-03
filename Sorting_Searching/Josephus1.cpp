#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    vector<int> removal_order;

    while (!dq.empty())
    {
        // skip one child: move front to back
        int skip = dq.front();
        dq.pop_front();
        dq.push_back(skip);

        // remove next child
        int removed = dq.front();
        dq.pop_front();
        removal_order.push_back(removed);
    }

    for (int x : removal_order)
        cout << x << " ";
}
