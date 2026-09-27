// Q7.) String Encryption Using Key Character
// You are given a list of characters and a plaintext string.
// You must choose one character from the list to determine the key for encryption.
// Key Rule
// The key is the alphabetical position of the selected character
// (A=1, B=2, …, Z=26).
// Example:
// Selected character T → key = 20
// Encryption Rule
// For each letter in the input string:
// encrypted_value = alphabetical_position(letter) + key
// Print all encrypted values as space-separated numbers.
// Input
// A list of characters
// A selected character (to determine the key)
// A plaintext string (uppercase)
// Output
// The key value
// Space-separated encrypted numbers
// Example
// Input
// Characters: [A, U, T, Y]Selected: TString: CAT
// Output
// Key: 20 Encrypted: 23 21 40


#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<char>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"select key";
    char ch;
    cin>>ch;

    cout<<"string";
    string s;
    cin>>s;

    int keyvalue=ch-'A'+1;
    cout<<"key:"<<keyvalue<<endl;

    cout<<"encrypted"<<endl;
    for(int i=0;i<s.size();i++)
    {
        int pos=s[i]-'A'+1+keyvalue;
        cout<<pos<<" ";
    }

    return 0;

}