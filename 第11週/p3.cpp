#include <iostream>
#include <algorithm>
using namespace std;

struct p
{
    int x;
    int y;
} a[1000];

bool cmp(p a,p b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    int n,i;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> a[i].x >> a[i].y;
    sort(a,a+n,cmp);
    for(i=0;i<n;i++)
        cout << a[i].x << " " << a[i].y << "\n";
}