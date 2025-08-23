#include <iostream>
#include <algorithm> // For std::max

int main()
{
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Number of test cases
    while (t--)
    {
        long long y, x; // Use long long to prevent overflow
        std::cin >> y >> x;

        long long z = std::max(y, x);
        long long ans = 0;

        // The square of the previous layer's dimension
        long long prev_square = (z - 1) * (z - 1);

        if (z % 2 == 0)
        { // z is even
            if (y == z)
            { // On the bottom row (moving left)
                ans = z * z - x + 1;
            }
            else
            { // On the right column (moving down)
                ans = prev_square + y;
            }
        }
        else
        { // z is odd
            if (x == z)
            { // On the right column (moving up)
                ans = z * z - y + 1;
            }
            else
            { // On the bottom row (moving right)
                ans = prev_square + x;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}