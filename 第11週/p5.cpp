#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <algorithm>
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

int a[100],b[100];

signed main()
{
    fastio;
    int n,d,r,i,ans;
    while(cin >> n >> d >> r && (n || d || r))
    {
        rep(i,n) cin >> a[i];
        rep(i,n) cin >> b[i];
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        ans=0;
        rep(i,n)
            ans+=max(int(0),(a[i]+b[i]-d)*r);
        cout << ans << "\n";
    }
}