#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    char colors[] = {'A', 'B', 'C', 'D'};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                char color = colors[k];
                if (color == grid[i][j])
                    continue;
                if (i > 0 && color == grid[i - 1][j])
                    continue;
                if (j > 0 && color == grid[i][j - 1])
                    continue;
                grid[i][j] = color;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}