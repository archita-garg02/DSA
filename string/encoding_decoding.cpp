// Q6.) Encoding–Decoding Problem
// You are given a plaintext word made up of alphabetic characters only.
// Your task is to encode this word and also be able to decode an encoded sequence back to the original word.
// Encoding Rules
// Convert each letter to its alphabetical position
// (a = 1, b = 2, …, z = 26).
// For every letter except the last, the encoded value is:
// 2 + (letter position)
// The last letter is encoded as only its alphabetical position.
// Output all encoded values as space-separated tokens.
// Decoding Rules
// Given a list of encoded tokens:
// For all tokens except the last, subtract 2 to get the original letter position.
// For the last token, use it directly as the letter position.
// Convert positions back to letters to obtain the original word.
// ________________________________________
// Input
// A single word containing only alphabetic characters.
// For decoding, input will be space-separated numeric tokens.
// Output
// For encoding: space-separated encoded tokens.
// For decoding: the recovered plaintext word.
// Example
// Input (word):
// hello
// Output (encoded):
// 28 25 212 212 15
// Input (encoded tokens):
// 28 25 212 212 15
// Output (decoded word):
// hello

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string s;
    cin>>s;

    vector<string>arr;

    cout<<"encoded"<<endl;
    for(int i=0;i<s.size();i++)
    {
        int pos=s[i]-'a'+1;
        if(i!=s.size()-1)
        {
            string ans="2"+to_string(pos);
            arr.push_back(ans);  
        }

        else arr.push_back(to_string(pos));  
    }

    for(string i:arr)
    {
        cout<<i<<" ";
    }

    cout<<endl<<"decoded"<<endl;

    for(int i=0;i<arr.size();i++)
    {
        int pos;
        if(i!=arr.size()-1)
        {
            string k = arr[i].substr(1);
            pos=stoi(k);
        }
        else 
        {
            pos=stoi(arr[i]);
        }

        char ch='a'+pos-1;
        cout<<ch;
    }

    return 0;

}