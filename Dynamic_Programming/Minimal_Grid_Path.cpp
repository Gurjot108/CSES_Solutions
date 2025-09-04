#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    string ans;
    vector<pair<int, int>> frontier = {{0, 0}};
    ans.push_back(grid[0][0]);

    for (int step = 1; step < 2 * n - 1; step++)
    {
        vector<pair<int, int>> candidates;
        char best = 'Z' + 1;

        // exploring neighbors
        for (auto [i, j] : frontier)
        {
            if (i + 1 < n)
            {
                best = min(best, grid[i + 1][j]);
                candidates.push_back({i + 1, j});
            }

            if (j + 1 < n)
            {
                best = min(best, grid[i][j + 1]);
                candidates.push_back({i, j + 1});
            }
        }
        vector<pair<int, int>> next;
        for (auto [i, j] : candidates)
        {
            if (grid[i][j] == best)
                next.push_back({i, j});
        }

        ans.push_back(best);
        frontier.swap(next);
    }

    return 0;
}