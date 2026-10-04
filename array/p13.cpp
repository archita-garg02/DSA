// 22. Next Greater Element
// Input:
// 4 5 2 10

// Output:
// 5 10 10 -1


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    vector<int>ans(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    stack<int>st;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[i]>=st.top())
        {
            st.pop();
        }

        if(st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    for(int i:ans)
    {
        cout<<i;
    }
}
