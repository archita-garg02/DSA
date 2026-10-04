// *****
// ****
// ***
// **
// *

// i    j
// 1    1->5
// 2    1->4
// 3    1->3
// 4    1->2
// 5    1->1


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=i ;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
