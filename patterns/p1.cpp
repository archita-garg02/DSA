// For N = 5, the pattern is:
// 9 8 7 6 5 4 3 2 1
//   8 7 6 5 4 3 2
//     7 6 5 4 3
//       6 5 4
//         5
//       4 5 6
//     3 4 5 6 7
//   2 3 4 5 6 7 8
// 1 2 3 4 5 6 7 8 9



#include<iostream>
using namespace std ;

int main()
{
    int n;
    cin>>n;


    //first half

    for(int i=1;i<=n;i++)
    {
        for(int space=1;space<i;space++)
        {
            cout<<" ";
        }

        for(int j=2*n-i;j>=i;j--)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    //secondhalf

    for(int i=1;i<n;i++)
    {
        for(int space = 1; space < n-i; space++)
        {
            cout <<" ";
        }

        for(int j=n-i;j<=n+i;j++)
        {
            cout<<j<<" ";
        }

        cout<<endl;
    }
}