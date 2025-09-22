#include <bits/stdc++.h>
using namespace std;

class Solver {
public:
    int tilingRectangle(int n, int m) {
        if (n > m) swap(n, m);
        N = n; M = m;
        heights.assign(M, 0);
        minRecCount.assign(N * M + 1, 1e9);
        initMinRecCount(N * M);
        best = dp_upper(n, m); // 初始上界
        dfs(0);
        return best;
    }

private:
    int N, M, sum = 0;
    vector<int> heights, minRecCount;
    int best;

    int leftMinPos() {
        int pos = 0, mn = heights[0];
        for (int i = 1; i < M; ++i) if (heights[i] < mn) { mn = heights[i]; pos = i; }
        return pos;
    }

    int difCheck() {
        int ret = 1;
        bool flag = false;
        if (heights[0] == N) {
            ret--, flag = true;
        }
        for (int i = 1; i < M; i++) {
            if (heights[i] - heights[i - 1]) ++ret;
            if (heights[i] == N) {
                if (!flag) ret--, flag = true;
            } else flag = false;
        }
        return ret;
    }

    void dfs(int used) {
        if (used >= best) return;
        int rem = N * M - sum;
        if (rem == 0) { best = min(best, used); return; }

        int lb = max(minRecCount[rem], difCheck());

        if (used + lb - 1 >= best) return;

        int c = leftMinPos();
        int baseH = heights[c];
        if (baseH >= N) return;

        int r = c;
        while (r < M && heights[r] == baseH) ++r;
        int maxWidth = r - c;
        int maxK = min(maxWidth, N - baseH);

        for (int k = maxK; k >= 1; --k) {
            for (int j = c; j < c + k; ++j) heights[j] += k;
            sum += k * k;
            dfs(used + 1);
            for (int j = c; j < c + k; ++j) heights[j] -= k;
            sum -= k * k;
        }
    }

    int dp_upper(int a, int b) {
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX / 2));
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                for (int k = 1; k < i; ++k) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                for (int k = 1; k < j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
        return dp[a][b];
    }

    void initMinRecCount(int sz) {
        minRecCount[0] = 0;
        for (int i = 1; i * i <= sz; i++) {
            for (int j = i * i; j <= sz; j++) {
                minRecCount[j] = min(minRecCount[j], minRecCount[j - i * i] + 1);
            }
        }
    }
};

signed main()
{
    freopen("動態規劃2.txt", "w", stdout);
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            Solver solver;
            cout << solver.tilingRectangle(i, j) << "\n";
        }
    }
}