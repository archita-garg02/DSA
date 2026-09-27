#include<iostream>
#include<vector>

using namespace std;

int missingnumber(vector<int>& arr , int n)
{
    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }

    int expectedSum = n * (n + 1) / 2;

    return expectedSum-sum;


}

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<missingnumber(arr,n);

    return 0;
}