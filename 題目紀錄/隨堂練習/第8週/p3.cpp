#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    string s[2]={"FAIL!","PASS!"};
    bool c[4][11];
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<=10;j++)
            c[i][j]=(j-i>=7);
    }
    while(cin >> a >> b)
        cout << s[c[a][b]] << "\n";
}