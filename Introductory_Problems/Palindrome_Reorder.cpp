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

    int n;
    cin >> n;

    vector<string> ans;
    int total = 1 << n;
    for (int i = 0; i < total; i++)
    {
        int g = i ^ (i >> 1); // Gray code in integer form
        ans.push_back(bitset<32>(g).to_string().substr(32 - n));
    }

    // Output the Gray codes
    for (const string &code : ans)
    {
        cout << code << "\n";
    }

    return 0;
}