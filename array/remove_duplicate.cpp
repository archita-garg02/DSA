#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cout<<endl;
    }

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[j])
        {
            j++;
            swap(arr[i],arr[j]);
        }
    }

    for(int i=0;i<j+1;i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}