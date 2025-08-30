#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> start, end;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int dx[] = {1, -1, 0, 0}; // down, up, right, left
    int dy[] = {0, 0, 1, -1};
    char dir[] = {'D', 'U', 'R', 'L'};

    // Read the grid and locate A and B
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'B')
                end = {i, j};
        }
    }

    // Move array to reconstruct path
    vector<vector<char>> move(n, vector<char>(m, 0));

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    bool found = false;

    // BFS
    while (!q.empty() && !found)
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = x + dx[i];
            int col = y + dy[i];

            if (row >= 0 && col >= 0 && row < n && col < m && !vis[row][col] && grid[row][col] != '#')
            {
                vis[row][col] = 1;
                move[row][col] = dir[i];
                q.push({row, col});
                if (row == end.first && col == end.second)
                {
                    found = true;
                    break;
                }
            }
        }
    }

    // Check if path exists
    if (!vis[end.first][end.second])
    {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct path
    string path = "";
    int x = end.first, y = end.second;
    while (make_pair(x, y) != start)
    {
        char d = move[x][y];
        path += d;
        if (d == 'U')
            x++; // we came from up, so go down
        else if (d == 'D')
            x--; // we came from down, so go up
        else if (d == 'L')
            y++; // we came from left, so go right
        else if (d == 'R')
            y--; // we came from right, so go left
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}
