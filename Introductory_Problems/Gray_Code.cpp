#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int to, int aux)
{
    if (n == 0)
        return; // Base case: no disk to move

    // Step 1: Move n-1 disks from 'from' to 'aux' using 'to' as auxiliary
    hanoi(n - 1, from, aux, to);

    // Step 2: Move the nth (largest) disk from 'from' to 'to'
    cout << from << " " << to << "\n";

    // Step 3: Move n-1 disks from 'aux' to 'to' using 'from' as auxiliary
    hanoi(n - 1, aux, to, from);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 3, 2);
    return 0;
}
// from is the source , to is the destination , aux is the auxiliary or helper