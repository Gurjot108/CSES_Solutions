#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n); // {duration, deadline}

    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    // Sort tasks by duration (Shortest Processing Time first)
    sort(tasks.begin(), tasks.end());

    long long time = 0, reward = 0;
    for (auto &task : tasks)
    {
        int a = task.first, d = task.second;
        time += a;
        reward += d - time;
    }

    cout << reward << "\n";

    return 0;
}

/*
| Order      | Use in comparator | Meaning                 |
| ---------- | ----------------- | ----------------------- |
| Ascending  | `<`               | smaller comes **first** |
| Descending | `>`               | larger comes **first**  |

*/