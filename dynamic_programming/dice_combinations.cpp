#include<iostream>
#include<vector>
using namespace std;

vector<int>dp(100,-1);

int helper(int n){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];

    int sum=0;
    for(int i=1;i<=6;i++)
    {
        if(n-i<0) break;
        sum=sum+helper(n-i);
    }
    dp[n]=sum;
    return sum;
}

int main(){
    int n;
    cin>>n;

    int ans= helper(n);
    cout<<ans;
    return 0;
}