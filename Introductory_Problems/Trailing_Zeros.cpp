#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> b >> a;
        if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}