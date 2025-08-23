#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    if (n == 3 || n == 2)
    {
        cout << "NO SOLUTION" << "\n";
        return 0;
    }
    for (long long i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            cout << i << " ";
    }
    for (long long i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
            cout << i << " ";
    }
    return 0;
}