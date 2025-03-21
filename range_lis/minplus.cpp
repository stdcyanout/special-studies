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

using v2 = vector<vector<int>>;
const int INF = 0x3F3F3F3F3F3F3F3F;

v2 operator*(v2& a, v2& b)
{
    int n = a.size(), m = b.size(), k = b[0].size(), x, y, z;
    v2 c(n, vector<int>(k, INF));
    rep(x, n) rep(y, k)
    {
        rep(z, m)
        {
            c[x][y] = min(c[x][y], a[x][z] + b[z][y]);
        }
    }
    return c;
}

signed main()
{
    fastio;
    int n, m, k, i, j;
    cin >> n >> m >> k;
    v2 a(n, vector<int>(m, 0));
    v2 b(m, vector<int>(k, 0));
    rep(i, n) rep(j, m)
        cin >> a[i][j];
    rep(i, m) rep(j, k)
        cin >> b[i][j];
    v2 c = a * b;
    rep(i, n) rep(j, k)
        cout << c[i][j] << " \n"[j == k - 1];
}
