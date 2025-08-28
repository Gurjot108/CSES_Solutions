#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, x;
    cin >> n >> x;
    vector<long long> weights;
    for (long long i = 0; i < n; i++)
    {
        long long y;
        cin >> y;
        weights.push_back(y);
    }
    long long count = 0;
    sort(weights.begin(), weights.end());
    if (*max_element(weights.begin(), weights.end()) > x)
    {
        return -1;
    }
    long long i = 0, j = n - 1;
    while (i <= j)
    {
        if ((weights[i] + weights[j]) <= x)
        {
            count++;
            i++;
            j--;
        }
        else
        {
            count++;
            j--;
        }
    }

    cout << count << "\n";

    return 0;
}