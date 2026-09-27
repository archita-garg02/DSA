#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int left=0;
    int mid=0;
    int right=n-1;

    while(left<right)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[left]);
            left++;
        }

        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[right]);
            right--;
        }

        mid++; 
    }


    for(int i:arr)
    {
        cout<<i;
    }
    
    return 0;
}