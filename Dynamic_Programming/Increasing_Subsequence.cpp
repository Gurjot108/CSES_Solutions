#include <bits/stdc++.h>
using namespace std;

long long getAns(vector<long long> &arr, long long n, long long ind, long long prev_index, vector<vector<long long>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];

    long long notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);

    long long take = 0;

    if (prev_index == -1 || arr[ind] > arr[prev_index])
    {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }

    return dp[ind][prev_index + 1] = max(notTake, take);
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n + 1, -1));

    cout << getAns(arr, n, 0, -1, dp);

    return 0;
}