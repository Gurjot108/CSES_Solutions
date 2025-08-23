#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'A']++;

    // Initial feasibility check
    int maxFreq = *max_element(freq.begin(), freq.end());
    if (maxFreq > (n + 1) / 2)
    {
        cout << -1 << "\n";
        return 0;
    }

    string ans;
    ans.reserve(n);
    char last = '#';

    for (int i = 0; i < n; i++)
    {
        bool placed = false;

        for (int c = 0; c < 26; c++)
        {
            if (freq[c] == 0)
                continue;
            char ch = 'A' + c;
            if (ch == last)
                continue; // cannot place same as last

            // Tentatively place
            freq[c]--;
            int remaining = n - (i + 1);

            // update max frequency efficiently
            int newMax = *max_element(freq.begin(), freq.end());

            if (newMax <= (remaining + 1) / 2)
            {
                ans.push_back(ch);
                last = ch;
                placed = true;
                break;
            }
            // rollback if not feasible
            freq[c]++;
        }

        if (!placed)
        {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << ans << "\n";
}