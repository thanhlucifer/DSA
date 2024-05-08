#include<bits/stdc++.h>
using namespace std;

// Maximum number of digits in output
#define MAX 50

// Prints the smallest number 
// whose digits multiply to n
void findSmallest(int n)
{
    int i, j = 0;

    // To store digits of result
    // in reverse order
    int res[MAX]; 

    // Case 1: If number is smaller than 10
    if (n < 10)
    {
        cout << n + 10;
        return;
    }

    // Case 2: Start with 9 and
    // try every possible digit
    for (i = 9; i > 1; i--)
    {
        // If current digit divides n, then store all
        // occurrences of current digit in res
        while (n % i == 0)
        {
            n = n / i;
            res[j] = i;
            j++;
        }
    }

    // If n could not be broken 
    // in form of digits (prime factors 
    // of n are greater than 9)
    if (n > 10)
    {
        cout << "Not possible";
        return;
    }

    // If the result has less than two digits,
    // we need to add more digits to it.
    if (j < 2) {
        cout << res[j] * 10 + res[j-1];
        return;
    }

    // Print the result array in reverse order
    for (i = j - 1; i >= 0; i--)
        cout << res[i];
}

// Driver Code
int main()
{
    findSmallest(1);
    cout << "\n";

    findSmallest(36);
    cout << "\n";

    findSmallest(13);
    cout << "\n";

    findSmallest(100);
    return 0;
}
