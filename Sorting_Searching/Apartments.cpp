#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> demanded_size;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        demanded_size.push_back(x);
    }

    vector<int> apart_size;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        apart_size.push_back(x);
    }

    sort(apart_size.begin(), apart_size.end());
    sort(demanded_size.begin(), demanded_size.end());

    int count = 0, i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(demanded_size[i] - apart_size[j]) <= k)
        {
            i++;
            j++;
            count++;
        }
        else if (apart_size[j] < demanded_size[i] - k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << count;

    return 0;
}