#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
using namespace std;

int a[100],b[100];

signed main()
{
    fastio;
    int n,d,r,i,ans;
    while(cin >> n >> d >> r && (n || d || r))
    {
        for(i=0;i<n;i++) cin >> a[i];
        for(i=0;i<n;i++) cin >> b[i];
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        ans=0;
        for(i=0;i<n;i++)
            ans+=max(int(0),(a[i]+b[i]-d)*r);
        cout << ans << "\n";
    }
}