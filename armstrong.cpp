// Armstrong Number Password
// - Given two numbers, find all Armstrong numbers between them.
// - Add all digits of all Armstrong numbers to generate the password.
// - Example:Input: 1, 500
//   Output: 86


#include<iostream>
#include<cmath>
using namespace std;

int calsize(int number)
{
    int size=1;

    while(number>9)
    {
        number=number/10;
        size++;
    }

    return size;

}

bool armstrong(int number)
{
    int size=calsize(number);
    int original = number;
    int sum=0;

    while(number>0)
    {
        int var=number%10;
        number=number/10;
        sum=sum+pow(var,size);
    }

    if(sum==original) return true;
    else return false;

}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=n;i<=m;i++)
    {
        int ans=armstrong(i);
        if(ans==1) cout<<i;
    }
}