// *****
//  ****
//   ***
//    **
//     *


// i    j         space
// 1    1->5      0   
// 2    1->4      1->1
// 3    1->3      1->2
// 4    1->2      1->3
// 5    1->1      1->4


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int space=1;space<=i-1;space++)
        {
            cout<<" ";
        }

        for(int j=i ;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}