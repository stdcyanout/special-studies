#include <bits/stdc++.h>
using namespace std;

class Solver {
public:
    int tilingRectangle(int n, int m) {
        if (n > m) swap(n, m);
        N = n; M = m;
        heights.assign(M, 0);
        lm.resize(M);
        rm.resize(M);
        best = dp_upper(n, m); // 初始上界
        dfs(0);
        return best;
    }

private:
    int N, M;
    vector<int> heights;
    int best;
    stack<int> s;
    vector<int> lm, rm;

    int leftMinPos() {
        int pos = 0, mn = heights[0];
        for (int i = 1; i < M; ++i) if (heights[i] < mn) { mn = heights[i]; pos = i; }
        return pos;
    }

    int remainingArea() {
        int sum = 0;
        for (int x : heights) sum += x;
        return N * M - sum;
    }

    // 計算整個板上能放的最大方塊邊長（安全的全域最大）
    int computeGlobalMaxK() {
        for (int i = 0; i < M; i++) {
            while (!s.empty() && heights[s.top()] <= heights[i]) {
                rm[s.top()] = i;
                s.pop();
            }
            if (!s.empty()) lm[i] = s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        int ret = 0;
        for (int i = 0; i < M; i++) {
            ret = max(ret, min(rm[i] - lm[i] - 1, N - heights[i]));
        }
        return ret;
    }

    void dfs(int used) {
        if (used >= best) return;
        int rem = remainingArea();
        if (rem == 0) { best = min(best, used); return; }

        // --- 安全的下界剪枝（使用整個板上的最大方塊） ---
        int globalMaxK = computeGlobalMaxK();
        if (globalMaxK == 0) return; // 沒地方放（理論上不會到這）
        int areaBig = globalMaxK * globalMaxK;
        int lb = (rem + areaBig - 1) / areaBig;
        if (used + lb >= best) return;

        int c = leftMinPos();
        int baseH = heights[c];
        if (baseH >= N) return;

        int r = c;
        while (r < M && heights[r] == baseH) ++r;
        int maxWidth = r - c;
        int maxK = min(maxWidth, N - baseH);

        for (int k = maxK; k >= 1; --k) {
            for (int j = c; j < c + k; ++j) heights[j] += k;
            dfs(used + 1);
            for (int j = c; j < c + k; ++j) heights[j] -= k;
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
};

int main() {
    int n, m;
    cin >> n >> m;
    clock_t a, b;
    a = clock();
    Solver solver;
    cout << solver.tilingRectangle(n, m) << "\n";
    b = clock();
    cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << "\n";
    return 0;
}