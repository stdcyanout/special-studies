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

double a[500][10], b[500];

signed main()
{
    for (int kk = 0; kk < 10; kk++) {
        string s = "一維枚舉1-30-";
        s += char(kk + '0');
        s += ".txt";
        freopen(s.c_str(), "r", stdin);
        for(int i = 1; i <= 465; i++) {
            cin >> a[i][kk];
        }
    }
    freopen("一維枚舉.txt", "w", stdout);
    cout << fixed << setprecision(6);
    for (int i = 1; i <= 465; i++) {
        sort(a[i], a[i] + 10);
        b[i] = (a[i][2] + a[i][3] + a[i][4] + a[i][5] + a[i][6] + a[i][7]) / 6;
        cout << b[i] << "\n";
    }
}