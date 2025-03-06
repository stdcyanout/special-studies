#include <bits/stdc++.h>
using namespace std;

#define N 60
#define pii pair<int, int>
#define F first
#define S second
#define lc 2 * id + 1
#define rc 2 * id + 2

const int INF = 1e9;
int n, m, ret;

/* Segment Tree */
struct node {
    pii val;
    int tag;
} seg[4 * N];

void pull (int id) {
    seg[id].val = min(seg[lc].val, seg[rc].val);
}

void build (int L, int R, int id) {
    if (L == R - 1) {
        seg[id].val.S = L;
        return;
    }
    int M = (L + R) / 2;
    build(L, M, lc);
    build(M, R, rc);
    pull(id);
}

void push (int id) {
    seg[lc].val.F += seg[id].tag;
    seg[rc].val.F += seg[id].tag;
    seg[lc].tag += seg[id].tag;
    seg[rc].tag += seg[id].tag;
    seg[id].tag = 0;
}

void update (int L, int R, int id, int l, int r, int val) {
    if(R <= l || r <= L)
        return;
    if(l <= L && R <= r)
    {
        seg[id].val.F += val;
        seg[id].tag += val;
        return;
    }
    int M = (L + R) / 2;
    push(id);
    update(L, M, lc, l, r, val);
    update(M, R, rc, l, r, val);
    pull(id);
}

int at (int L, int R, int id, int pos) {
    if(L == R - 1)
        return seg[id].val.F;
    int M = (L + R) / 2;
    push(id);
    if(pos < M)
        return at(L, M, lc, pos);
    else
        return at(M, R, rc, pos);
}

void solve (int h, int k, int c) {
    if (c >= ret)
        return;
    int l = 0, ah = at(0, m, 0, h), ahl = ah;
    while (h + l < m && k + l < n && ah >= ahl) {
        l = l + 1;
        update(0, m, 0, h, h + l, l);
        if (h + l < m && ah >= (ahl = at(0, m, 0, h + l)))
            solve(h + l, k, c + 1);
        else {
            pii t = seg[0].val;
            if (t.F < n)
                solve(t.S, t.F, c + 1);
            else
                ret = min(c, ret);
        }
        update(0, m, 0, h, h + l, -l);
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
    clock_t a, b;
    cin >> n >> m;
    a = clock();
    init();
    build(0, m, 0);
    solve(0, 0, 1);
    b = clock();
    cout << ret << endl;
    cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << endl;
}