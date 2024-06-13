#include <iostream>
using namespace std;
int a[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j;
    while(cin >> n)
    {
        for(i=0;i<n;i++)
            cin >> a[i];
        for(i=0;i<n;i++)
            for(j=0;j<i;j++)
                if(a[i]<a[j])
                    swap(a[i],a[j]);
        for(i=0;i<n;i++)
            cout << a[i] << " \n"[i==n-1];
    }
}