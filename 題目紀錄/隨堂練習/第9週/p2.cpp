#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin,s);
    for(i=0;i<s.length();i++)
    {
        if('A'<=s[i]&&s[i]<='Z')
            cout << char((s[i]-'A'+n)%26+'A');
        else if('a'<=s[i]&&s[i]<='z')
            cout << char((s[i]-'a'+n)%26+'a');
        else
            cout << s[i];
    }
    cout << "\n";
}