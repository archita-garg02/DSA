//  5.) Circular Array – Vanished Kriyas Problem
// A circular array contains n kriyas numbered from 1 to n. You are also given a selected kriya x. When kriya x is selected, the kriyas that are adjacent to it in the circular array vanish.
// The vanished kriyas are determined as follows:
// If x is neither the first nor the last kriya, then the vanished kriyas are x − 1 and x + 1.
// If x = 1, then the vanished kriyas are n and 2.
// If x = n, then the vanished kriyas are n − 1 and 1.
// Your task is to find the number of vanished kriyas for the selected kriya x.
// Example:
// For a circular array {1, 2, 3, 4}, if x = 2, then the vanished kriyas are 1 and 3.
// For n = 10 and x = 1, the vanished kriyas are 10 and 2.


#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int left, right;

    if(x == 1)
    {
        left = n;
        right = 2;
    }
    else if(x == n)
    {
        left = n - 1;
        right = 1;
    }
    else
    {
        left = x - 1;
        right = x + 1;
    }

    cout << left << " and " << right;

    return 0;
}
