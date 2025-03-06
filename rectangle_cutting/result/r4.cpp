#include <bits/stdc++.h>
using namespace std;

#define N 60

int n, m, ret, cnt = 0;
int a[N];

void solve (int h, int k, int c) {
    if (c >= ret)
        return;
    int l = 0;
    while (h + l < m && k + l < n && a[h] >= a[h + l]) {
        l = l + 1;
        for (int i = 0; i < l; i++)
            a[h + i] += l;
        if (h + l < m && a[h] - l >= a[h + l])
            solve(h + l, k, c + 1);
        else {
            int u = 0;
            for (int i = 0; i < m; i++) {
                if (a[i] < a[u])
                    u = i;
            }
            int v = a[u];
            if (v < n)
                solve(u, v, c + 1);
            else
                ret = min(c, ret);
        }
        for (int i = 0; i < l; i++)
            a[h + i] -= l;
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
    solve(0, 0, 1);
    b = clock();
    cout << ret << endl;
    cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << endl;
}