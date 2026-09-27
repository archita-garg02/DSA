#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> dp(n+1, vector<int>(3,0));

    int a,b,c;

    for(int i=1; i<=n; i++)
    {
        cin >> a >> b >> c;

        if(i==1)
        {
            dp[i][0] = a;
            dp[i][1] = b;
            dp[i][2] = c;
        }
        else
        {
            dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);
        }
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});

    return 0;
}