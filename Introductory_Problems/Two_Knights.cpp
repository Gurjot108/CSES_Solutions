#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<long long> a, b;
    if (n % 4 == 0)
    {
        for (long long i = 1; i <= n; i += 4)
        {
            a.push_back(i);
            a.push_back(i + 3);
            b.push_back(i + 2);
            b.push_back(i + 1);
        }
    }
    else if (n % 4 == 3)
    {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);

        for (long long i = 4; i <= n; i += 4)
        {
            a.push_back(i);
            a.push_back(i + 3);
            b.push_back(i + 2);
            b.push_back(i + 1);
        }
    }
    cout << a.size() << "\n";
    for (long long x : a)
    {
        cout << x << "\n";
    }
    cout << b.size() << "\n";
    for (long long x : b)
    {
        cout << x << "\n";
    }
    return 0;
}