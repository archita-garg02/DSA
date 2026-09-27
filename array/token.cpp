#include<iostream>
#include<unordered_map>
#include<vector>
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

    unordered_map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }

    for(int i=0;i<n;i++){
        if(mp[arr[i]]==1)
        {
            cout<<arr[i];
            break;
        } 
    }

    return 0;
}