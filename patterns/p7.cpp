//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *


                 // i    space   j
//     *            1    1->4    1->1
//    ***           2    1->3    1->3
//   *****          3    1->2    1->5 
//  *******         4    1->1    1->7
// *********        5    1->0    1->9


                //  i    space   j
//  *******         1    1->0    1->7
//   *****          2    1->1    1->5
//    ***           3    1->2    1->3
//     *            4    1->3    1->1


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int space=1 ; space<=n-i ; space++)
        {
            cout<<" ";
        }

        for(int j = 1; j <=2 * i - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    for(int i = n - 1; i >= 1; i--)
    {
        // spaces
        for(int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }

        // stars
        for(int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
