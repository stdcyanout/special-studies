#include <bits/stdc++.h>
using namespace std;

#define N 60

int dp[N][N];

int main() {
    for (int kk = 0; kk < 10; kk++) {
        string s = "動態規劃1-30-";
        s += char(kk + '0');
        s += ".txt";
        freopen(s.c_str(), "w", stdout);
        for(int n = 1; n <= 30; n++) {
            for(int m = 1; m <= n ; m++) {
                clock_t a, b;
                a = clock();
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
                b = clock();
                cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << endl;
            }
        }
    }
}