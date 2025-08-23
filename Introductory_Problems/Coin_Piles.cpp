#include <iostream>
#include <algorithm> // For std::max
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'A']++;
    }
    int odd = 0, odd_index = -1;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 == 1)
        {
            odd++;
            odd_index = i;
        }
    }
    if (odd > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    string half = "";
    for (int i = 0; i < 26; i++)
    {
        int times = freq[i] / 2;
        for (int j = 0; j < times; j++)
        {
            half += char(i + 'A');
        }
    }
    string res = half;
    if (odd == 1)
    {
        res += char('A' + odd_index);
    }
    for (int i = half.size() - 1; i >= 0; i--)
    {
        res += half[i];
    }

    cout << res << endl;
    return 0;
}