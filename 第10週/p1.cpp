#include <iostream>
using namespace std;

void hanoi(int n,int a,int b)
{
    if(n>1)
        hanoi(n-1,a,3-a-b);
    cout << "Move ring " << n << " from " << char('A'+a) << " to " << char('A'+b) << "\n";
    if(n>1)
        hanoi(n-1,3-a-b,b);
}

int main()
{
    int n;
    while(cin >> n)
    {
        hanoi(n,0,2);
        cout << "\n";
    }
}