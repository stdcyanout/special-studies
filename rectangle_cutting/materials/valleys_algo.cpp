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
#define pb push_back
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

#define N 30

vector<pii> v;
vector<array<int, 3>> back;
int n, m, ret;

void simplify() {
    for (int i = 0; i < v.size(); ) {
        if (v[i].S == 0) {
            if (i + 1 < v.size()) {
                v[i + 1].F += v[i].F;
            }
            v.erase(v.begin() + i);
        }
        else i++;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i].F == 0) {
            if (i - 1 >= 0) {
                v[i - 1].S += v[i].S;
            }
            v.erase(v.begin() + i);
        }
    }
    if (v.empty()) v.push_back({0, n});
}

void add (int i, int x) {
    pii p = v[i];
    v[i] = {-x, p.S - x};
    v.insert(v.begin() + i, {p.F + x, x});
    if (v[i].F == 0) back.push_back({i - 1, v[i - 1].S, x});
    else back.push_back({i, 0, x});
    simplify();
}

void rm (int i, int k, int x) {
    if (k != 0) {
        pii t = v[i];
        v[i] = {0, t.S - k};
        v.insert(v.begin() + i, {t.F, k});
        i++;
    }
    pii p = v[i];
    v[i] = {x, p.S - x};
    v.insert(v.begin() + i, {p.F - x, x});
    simplify();
}

void rollback() {
    array<int, 3> cur = back.back();
    rm (cur[0], cur[1], cur[2]);
    back.pop_back();
}

void print() {
    for (pii p : v)
        cout << "(" << p.F << ", " << p.S << ")\n";
    cout << "\n";
}

void solve (int c) {
    if (c >= ret)
        return;

    int sum = 0, t = m + 1, mi = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i].F;
        if (sum < t) {
            t = sum;
            mi = i;
        }
    }

    int r = min(m - t, v[mi].S);
    for (int l = 1; l <= r; l++) {
        add(mi, l);
        if (v.size() == 1 && v[0].F == m && v[0].S == n) {
            ret = min(c, ret);
        } else {
            solve(c + 1);
        }
        rollback();
    }
}

void init () {
    int dp[N][N];
    memset(dp, 0x3F, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
    }
    ret = dp[n][m];
}

signed main()
{
    fastio;
    cin >> n >> m;
    v.pb({0, n});
    init();
    solve(1);
    cout << ret << endl;
}