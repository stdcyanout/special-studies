#include <bits/stdc++.h>
using namespace std;

typedef array<int, 41> arr;
arr res;
int n, m, i, j, MIN;
int dp[41][41];

void solve(arr a, int h, int k, int c)
{
    int l;
    c = c + 1;
    if(c < MIN)
    {
        l = 0;
        while(h + l < m && k + l <= n && a[h] >= a[h + l])
        {
            l = l + 1;
            for(i = 0; i < l; i++)
                a[h + i] += l;
            if(h + l < m && a[h] - l >= a[h + l])
                solve(a, h + l, k, c);
            else
            {
                h = min_element(a.begin(), a.begin() + m) - a.begin();
                k = a[h] + 1;
                if(k <= n)
                    solve(a, h, k, c);
                else
                    MIN = min(c, MIN);
                return;
            }
            for(i = 0; i < l; i++)
                a[h + i] -= l;
        }
    }
}

int f(int a, int b)
{
    int k;
    memset(dp, 0x3F, sizeof(dp));
    for(i = 1; i <= a; i++)
        for(j = 1; j <= b; j++)
        {
            if(i == j)
                dp[i][j] = 0;
            else
            {
                for(k = 1; k < i; k++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                for(k = 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    return dp[a][b] + 1;
}

signed main()
{
    clock_t a, b;
    cin >> n >> m;
    a = clock();
    MIN = f(n, m);
    solve(res, 0, 1, 0);
    b = clock();
    cout << "MIN = " << MIN << "\n";
    cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << "\n";
}