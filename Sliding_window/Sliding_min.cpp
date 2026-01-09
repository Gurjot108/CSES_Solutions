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

    // 1. Array Generation
    vector<long long> A(n);

    A[0] = x;

    for (int i = 1; i < n; ++i)
    {
        A[i] = (a * A[i - 1] + b) % c;
    }

    // 2. Sliding Window Minimum with Deque
    deque<int> window_indices;
    long long xor_sum_of_minimums;

    for (int i = 0; i < k; ++i)
    {
        // Remove larger/equal elements from the back (maintaining monotonicity)
        while (!window_indices.empty() && A[window_indices.back()] >= A[i])
        {
            window_indices.pop_back();
        }
        // Add the current element's index
        window_indices.push_back(i);
    }

    // XOR sum starts with the minimum of the first window
    xor_sum_of_minimums ^= A[window_indices.front()];

    for (int i = k; i < n; ++i)
    {
        if (!window_indices.empty() && window_indices.front() == i - k)
        {
            window_indices.pop_front();
        }

        // Handle arrival: Process the new element A[i]
        // Remove larger/equal elements from the back
        while (!window_indices.empty() && A[window_indices.back()] >= A[i])
        {
            window_indices.pop_back();
        }
        // Add the new element's index
        window_indices.push_back(i);

        // Update XOR sum with the minimum of the current window (at the front)
        xor_sum_of_minimums ^= A[window_indices.front()];
    }

    cout << xor_sum_of_minimums << endl;

    return 0;
}