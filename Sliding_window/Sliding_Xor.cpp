#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    if (!(cin >> n >> k))
        return 0;

    long long x, a, b, c;
    if (!(cin >> x >> a >> b >> c))
        return 0;

    vector<long long> A(n);

    A[0] = x;

    for (int i = 1; i < n; ++i)
    {
        A[i] = (a * A[i - 1] + b) % c;
    }

    long long current_window_sum = 0;
    long long xor_sum_of_windows = 0;

    for (int i = 0; i < k; ++i)
    {
        current_window_sum ^= A[i];
    }

    xor_sum_of_windows ^= current_window_sum;

    for (int i = k; i < n; ++i)
    {
        current_window_sum = current_window_sum ^ A[i - k] ^ A[i];
        xor_sum_of_windows ^= current_window_sum;
    }

    cout << xor_sum_of_windows << endl;

    return 0;
}