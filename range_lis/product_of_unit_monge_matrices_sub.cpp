// https://loj.ac/p/184
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

typedef array<array<int, 102>, 102> matrix;
matrix a, b;
int arr[102];
const int INF = 0x3F3F3F3F3F3F3F3F;
int n;

matrix operator*(const matrix& x, const matrix& y)
{
	int i, j, k;
	matrix res;
	foo(i, 1, n + 1) foo(j, 1, n + 1)
		res[i][j] = INF;
	foo(i, 1, n + 1) foo(j, 1, n + 1) foo(k, 1, n + 1)
		res[i][j] = min(res[i][j], x[i][k] + y[k][j]);
	return res;
}

signed main()
{
	fastio;
	int i, j, k, tmp;
	cin >> n;
	foo(i, 1, n)
		cin >> arr[i];
	foo(i, 1, n + 1) foo(j, 1, n + 1)
	{
		foo(k, i, n)
			a[i][j] += arr[k] < j;
	}
	foo(i, 1, n + 1)
		orange(a[i].begin() + 1, a[i].begin() + n + 2);
	foo(i, 1, n)
		cin >> arr[i];
	foo(i, 1, n + 1) foo(j, 1, n + 1)
	{
		foo(k, i, n)
			b[i][j] += arr[k] < j;
	}
	foo(i, 1, n + 1)
		orange(b[i].begin() + 1, b[i].begin() + n + 2);
	matrix c = a * b;
	foo(i, 1, n) foo(j, 2, n + 1)
		if(c[i][j] - c[i + 1][j] - c[i][j - 1] + c[i + 1][j - 1] == 1)
			cout << j - 1 << " \n"[i == n];
}