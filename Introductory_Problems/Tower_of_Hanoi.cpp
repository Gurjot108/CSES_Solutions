#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    sort(s.begin(), s.end()); // sort for lexicographical order

    vector<string> result;
    do
    {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << result.size() << "\n"; // total number of distinct strings
    for (auto &str : result)
        cout << str << "\n";

    return 0;
}
