// *
// **
// ***
// ****
// *****

// i    j
// 1    1
// 2    1->2
// 3    1->3
// 4    1->4
// 5    1->5


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0 ;j<i+1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}