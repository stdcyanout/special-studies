#include <iostream>
using namespace std;

int f(int x)
{
    return 2*x-3;
}

int g(int x,int y)
{
    return 2*x+y-7;
}

int h(int x,int y,int z)
{
    return 3*x-2*y+z;
}

int solve()
{
    string s;
    int x,y,z;
    cin >> s;
    if(s=="f")
    {
        x=solve();
        return f(x);
    }
    else if(s=="g")
    {
        x=solve();
        y=solve();
        return g(x,y);
    }
    else if(s=="h")
    {
        x=solve();
        y=solve();
        z=solve();
        return h(x,y,z);
    }
    else
        return stoi(s);
}

int main()
{
    cout << solve() << "\n";
}