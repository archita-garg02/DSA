//     *
//    **
//   ***
//  ****
// *****


// i    j         space
// 1    1         1->4   
// 2    1->2      1->3
// 3    1->3      1->2
// 4    1->4      1->1
// 5    1->5      0


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int space=1;space<=n-i;space++)
        {
            cout<<" ";
        }

        for(int j=1 ;j<i+1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}