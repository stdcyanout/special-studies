#include <bits/stdc++.h>
using namespace std;

#define N 505

int dp[N][N];

int main() {
    for (int kk = 0; kk < 10; kk++) {
        string s = "動態規劃500-";
        s += char(kk + '0');
        s += ".txt";
        freopen(s.c_str(), "w", stdout);
        int n = 500;
        for(int m = 1; m <= n; m++) {
            clock_t a, b;
            memset(dp, 0x3F, sizeof(dp));
            a = clock();
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
            b = clock();
            cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << endl;
        }
    }
}