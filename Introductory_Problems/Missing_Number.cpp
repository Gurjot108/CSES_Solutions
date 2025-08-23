#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    int maxlen = 1;
    int len = 1;
    for (int i = 1; i < n; i++)
    {

        if (s[i] == s[i - 1])
            len++;
        else
        {
            maxlen = max(len, maxlen);
            len = 1;
        }
    }
    maxlen = max(len, maxlen);
    cout << maxlen;
    return 0;
}