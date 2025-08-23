#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long ans = 0;
    while (n > 0)
    {
        n /= 5;
        ans += n;
    }
    cout << ans << "\n";
    return 0;
}