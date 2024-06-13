#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
using namespace std;
template <class ...T> void debug(T ...args)
{
    int cnt = sizeof...(T);
    ((cerr << "\e[1;31m"), ..., (cerr << args << (--cnt ? " " : "\e[0m\n")));
}
template <class T> void orange(T L, T R)
{
    cerr << "\e[1;31m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

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
    rep(i,n)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a,a+n,cmp);
    rep(i,n)
        cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
}