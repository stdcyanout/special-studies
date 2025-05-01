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

vector<pii> v;

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
}

void add (int i, int x) {
    pii p = v[i];
    v[i] = {-x, p.S - x};
    v.insert(v.begin() + i, {p.F + x, x});
    simplify();
}

void print() {
    for (pii p : v)
        cout << "(" << p.F << ", " << p.S << ")\n";
}

signed main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    v.pb({0, n});
    add(0, 3);
    add(1, 5);
    add(2, 2);
    add(3, 4);
    add(2, 1);
    print();
}