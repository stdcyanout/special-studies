#include <iostream>
using namespace std;

int solve(int n,int m,int k)
{
    if(k==0)
        return 0;
    return (solve(n-1,m,k-1)+m)%n;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    cout << solve(n,m,k)+1 << "\n";
}