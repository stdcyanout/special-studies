#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    string s,ans="";
    cin >> n >> s;
    for(i=0;i<n;i++)
        for(j=0;j<s.length();j+=n)
            if(i+j<s.length())
                ans+=s[i+j];
    cout << ans << "\n";
}