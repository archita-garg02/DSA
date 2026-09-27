// 2. Problem Statement:
// You are given an array of item prices P = [P1, P2, ..., Pn].
// You are also given a discount value D.
// You are allowed to apply the discount on only one item.
// The discount amount is equal to the GCD of all item prices:
// discount = GCD(P1, P2, ..., Pn)
// If you apply the discount on item Pi, its new price becomes:
// Pi - discount
// Your task is to determine on which item the discount should be applied so that the total cost of all items becomes minimum.
// Example:
// Prices = [50, 100, 150]
// GCD(50, 100, 150) = 50


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    int total = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    int g = arr[0];

    for(int i = 1; i < n; i++)
    {
        g = gcd(g, arr[i]);
    }

    int minimumCost = total - g;

    cout << minimumCost;

    return 0;
}