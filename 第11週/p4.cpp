#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
using namespace std;

struct p
{
    int x;
    int y;
    int z;
} a[1000];

bool cmp(p a,p b)
{
    if(a.x==b.x)
    {
        if(a.y==b.y)
            return a.z<b.z;
        return a.y<b.y;
    }
    return a.x<b.x;
}

signed main()
{
    fastio;
    int n,i;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a,a+n,cmp);
    for(i=0;i<n;i++)
        cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
}