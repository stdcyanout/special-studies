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

const int INF = 0x3F3F3F3F3F3F3F3F;
int n, m;
inline int coordinate(int x, int y)
{
    return x * (m + 1) + y;
}

signed main()
{
    fastio;
    string s, t;
    cin >> s >> t;
    n = s.length(), m = t.length();
    int i, j, k;
    vector<int> v((n + 1) * (m + 1));
    vector<vector<int>> dis((n + 1) * (m + 1));
    for(i = 0; i < (n + 1) * (m + 1); i++)
        dis[i].resize((n + 1) * (m + 1), ~INF);
    for(i = 0; i <= n; i++)
        for(j = 0; j < m; j++)
            dis[coordinate(i, j)][coordinate(i, j + 1)] = 0;
    for(j = 0; j <= m; j++)
        for(i = 0; i < n; i++)
            dis[coordinate(i, j)][coordinate(i + 1, j)] = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
        {
            if(s[i] == t[j])
                dis[coordinate(i, j)][coordinate(i + 1, j + 1)] = 1;
        }
    // floyd-warshall
    for(k = 0; k < (n + 1) * (m + 1); k++)
        for(i = 0; i < (n + 1) * (m + 1); i++)
            for(j = 0; j < (n + 1) * (m + 1); j++)
                dis[i][j] = max(dis[i][j], dis[i][k] + dis[k][j]);
    for(i = 1; i <= m; i++)
        for(j = i; j <= m; j++)
            cout << dis[coordinate(0, i - 1)][coordinate(n, j)] << " \n"[j == m];
}

// x = t / m, y = t % m;