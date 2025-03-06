#include <bits/stdc++.h>
using namespace std;

#define N 60

int dp[N][N];

int main() {
    freopen("動態規劃.txt", "w", stdout);
    memset(dp, 0x3F, sizeof(dp));
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 30; j++) {
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
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            cout << dp[i][j] << endl;
        }
    }
}