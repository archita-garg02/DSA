#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);


    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int var=arr[n-1];

    vector<int>ans;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>var)
        {
            ans.push_back(var);
            var=max(var,arr[i]);
        }
    }
    ans.push_back(var);
    reverse(ans.begin(),ans.end());
    for(int i:ans) cout<<i;
    return 0;
}