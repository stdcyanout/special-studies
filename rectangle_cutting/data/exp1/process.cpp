#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

double a[500], b[500], c[500];

signed main()
{
    // fastio;
    freopen("輾轉相除法.txt", "r", stdin);
    for(int i = 1; i <= 465; i++)
        cin >> a[i];
    freopen("動態規劃2.txt", "r", stdin);
    for(int i = 1; i <= 465; i++)
        cin >> b[i];
    freopen("最佳解.txt", "r", stdin);
    for(int i = 1; i <= 465; i++)
        cin >> c[i];
    freopen("data1.csv", "w", stdout);
    cout << "x,y\n";
    for (int i = 1; i <= 465; i++) {
        cout << i << "," << a[i]/c[i] << "\n";
    }
    freopen("data2.csv", "w", stdout);
    cout << "x,y\n";
    for (int i = 1; i <= 465; i++) {
        cout << i << "," << b[i]/c[i] << "\n";
    }
}