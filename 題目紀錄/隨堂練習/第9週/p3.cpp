#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k;
    string s,c;
    getline(cin,s);
    getline(cin,c);
    int d='~'-*max_element(s.begin(),s.end());
    for(i=0;i<s.length();i++)
        s[i]+=d;
    while(1)
    {
        for(i=0;i<s.length()-c.length()+1;i++)
        {
            for(j=0;j<c.length();j++)
            {
                if(s[i+j]!=c[j])
                    break;
                else if(j==c.length()-1)
                {
                    cout << s << "\n";
                    return 0;
                }
            }
        }
        for(i=0;i<s.length();i++)
            s[i]--;
    }
}