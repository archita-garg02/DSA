#include<iostream>
#include<string>
using namespace std;

int expand(string s , int left , int right)
{
    while(left>=0 && right<s.size() && s[left]==s[right])
    {
        left--;
        right++;
    }
    return right-left-1;
}

int main()
{
    string s;
    cin>>s;

    int maxlen=1;
    int start=0;

    for(int i=0;i<s.size();i++)
    {
        int len1=expand(s,i,i);
        int len2=expand(s,i,i+1);

        int len=max(len1,len2);

        if(maxlen<len)
        {
            maxlen=len;
            start=i-(len-1)/2;
        }
    }
    cout<<s.substr(start,maxlen)<<endl;
    return 0;
}