#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,s;
    while(cin >> a >> b >> c)
    {
        s=(a+b+c)/2;
        cout << sqrt(s*(s-a)*(s-b)*(s-c)) << "\n";
    }
}