// 3.) Perfect-Square Digit Sum Number
// Problem Statement:
// You are given an integer n.
// Your task is to generate any n-digit number such that:
// You square each of its digits,
// Then add all the squared values together,
// The final sum must be a perfect square.
// Output any one n-digit number that satisfies this condition.
// Example:
// For n = 3, a valid output is:
// 122
// Because:
// 1² + 2² + 2² = 1 + 4 + 4 = 9
// And 9 is a perfect square.


#include <iostream>
#include <cmath>
using namespace std;

bool helper(int num)
{
    int sum = 0;

    while (num > 0)
    {
        int var = num % 10;
        sum += var * var;
        num /= 10;
    }

    int root = sqrt(sum);

    return root * root == sum;
}

int main()
{
    int n;
    cin >> n;

    int start = 1;

    for (int i = 1; i < n; i++)
    {
        start *= 10;
    }

    int end = start * 10 - 1;

    for (int num = start + 1; num <= end; num++)
    {
        if (helper(num))
        {
            cout << num;
            break;
        }
    }

    return 0;
}