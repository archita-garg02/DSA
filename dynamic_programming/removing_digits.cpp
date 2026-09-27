#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> digits(int n) {
    vector<int> ans;

    while (n > 0) {
        if (n % 10 != 0)
            ans.push_back(n % 10);

        n /= 10;
    }

    return ans;
}

int helper(int n, vector<int>& dp) {

    if (n == 0)
        return 0;

    if(n<=9) return 1;

    if (dp[n] != -1)
        return dp[n];

    vector<int> d = digits(n);

    int minimum = INT_MAX;

    for (int i : d) {
        minimum = min(minimum, helper(n - i, dp));
    }

    return dp[n] = minimum + 1;
}

int main() {

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << helper(n, dp) << endl;

    return 0;
}