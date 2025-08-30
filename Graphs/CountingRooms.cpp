#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    int delrow[] = {1, 0, 0, -1};
    int delcol[] = {0, -1, 1, 0};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '.')
        {
            dfs(nrow, ncol, vis, grid);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                dfs(i, j, vis, grid);
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}