#include <bits/stdc++.h>
using namespace std;

long long helper(long long a, long long b, long long mod)
{

    long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long MOD = 1e9 + 7;
    long long n;
    cin >> n;
    cout << helper(2, n, MOD) << "\n";
    return 0;
}