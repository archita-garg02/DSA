// Reverse Words + Count Consonants
// - Create wordCountReverse().
// - Reverse the order of words in a sentence.
// - Append the number of consonants in each word.
// Example concept:
// Salesforce Developer

// Developer5 Salesforce6


#include<iostream>
#include<string>
#include<vector>
#include <cctype>
using namespace std;

int consonent(string s)
{
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||
           s[i]=='A' ||s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
           {
                continue;
           }
        else count++;
    }
    return count;
}

int main()
{
    string s;
    getline(cin, s);

    vector<string>arr;
    string word="";

    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            arr.push_back(word);
            word = "";
        }
        else word = word + s[i];
    }

    if(!word.empty())
    {
        arr.push_back(word);
    }

    for(int i=arr.size()-1;i>=0;i--)
    {
        int count=consonent(arr[i]);
        cout<<arr[i]<<count<<" ";
    }
}