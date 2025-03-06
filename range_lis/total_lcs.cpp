// https://codeforces.com/gym/101237/problem/G
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
#define lowbit(x) (x & -(x))
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
    cerr << "\e[1;33m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

int n, m, ih[2001][2001], iv[2001][2001];

signed main()
{
    fastio;
    string s, t;
    int i, j, k;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    for(j = 0; j <= m; j++)
        ih[0][j] = j;
    for(i = 0; i <= n; i++)
        iv[i][0] = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                ih[i][j] = iv[i][j - 1];
                iv[i][j] = ih[i - 1][j];
            }
            else
            {
                ih[i][j] = max(ih[i - 1][j], iv[i][j - 1]);
                iv[i][j] = min(ih[i - 1][j], iv[i][j - 1]);
            }
        }
    for(i = 0; i <= n; i++)
        orange(ih[i], ih[i] + m + 1);
    for(i = 1; i <= m; i++)
    {
        int ans = 0;
        for(j = i; j <= m; j++)
        {
            ans += ih[n][j] < i;
            cout << ans << " ";
        }
        cout << "\n";
    }
}