#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t a,b;
    char op;
    while(cin >> a >> op >> b)
    {
        if(op=='+')
            cout << a << " + " << b << " = " << a+b << "\n";
        else if(op=='-')
            cout << a << " - " << b << " = " << a-b << "\n";
        else if(op=='*')
            cout << a << " * " << b << " = " << a*b << "\n";
        else if(op=='/'&&b)
            cout << a << " / " << b << " = " << a/b << " ... " << a%b << "\n";
        else
            cout << "ERROR\n";
    }
}