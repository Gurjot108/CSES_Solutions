#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long q;
    cin >> q; // Number of queries

    while (q--)
    {
        long long k;
        cin >> k; // The k-th digit we want to find

        // Initialize variables for finding the correct "block" of numbers
        long long len = 1;   // Current digit length (1 for 1-digit numbers, 2 for 2-digit numbers, etc.)
        long long count = 9; // Number of numbers in the current block (9 for 1-digit, 90 for 2-digit, etc.)
        long long start = 1; // The first number in the current block (1 for 1-digit, 10 for 2-digit, etc.)

        // Step 1: Find the length of the number that contains the k-th digit
        while (k > len * count)
        {
            // If k is larger than the total digits in this block, subtract this block's digits
            k -= len * count;

            // Move to next block
            len++;       // Increase the length of numbers
            count *= 10; // Update the count of numbers in this new block (9→90→900...)
            start *= 10; // Update the starting number of this new block (1→10→100...)
        }

        // Step 2: Find the actual number that contains the k-th digit
        // (k-1)/len gives the 0-based index of the number inside the current block
        long long num = start + (k - 1) / len;

        // Step 3: Find the exact digit inside the number
        // Convert number to string to easily access individual digits
        string s = to_string(num);

        // (k-1) % len gives the 0-based index of the digit inside the number
        cout << s[(k - 1) % len] << "\n";
    }
