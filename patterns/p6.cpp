// *****
// *   *
// *   *
// *   *
// *****

// i    j         space
// 1    1->5      0   
// 2    1->5      2->4
// 3    1->5      2->4
// 4    1->5      2->4
// 5    1->5      0


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 || i == n || j == 1 || j == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
