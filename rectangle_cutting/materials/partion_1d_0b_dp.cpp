#include <bits/stdc++.h>
using namespace std;

typedef array<int, 51> arr;
arr res;
int n, m, i, j, MIN;
int dp[61][61], solution[61][61];
vector<int> path, optimal;

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
            path.push_back(l);
            if(h + l < m && a[h] - l >= a[h + l])
                solve(a, h + l, k, c);
            else
            {
                h = min_element(a.begin(), a.begin() + m) - a.begin();
                k = a[h] + 1;
                if(k <= n)
                    solve(a, h, k, c);
                else
                {
                    if(c < MIN)
                        MIN = c, optimal = path;
                }
                path.pop_back();
                return;
            }
            for(i = 0; i < l; i++)
                a[h + i] -= l;
            path.pop_back();
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

void rollback(int h, int k, int c)
{
    int l = optimal[c];
    c = c + 1;
    for(i = 0; i < l; i++)
        for(j = 0; j < l; j++)
            solution[h + i][k + j] = l;
    if(h + l < m && solution[h + l][k] == 0)
        rollback(h + l, k, c);
    while(solution[h][k] != 0 && k < n)
    {
        h = h + solution[h][k];
        if(h == m)
        {
            h = 0;
            k = k + 1;
        }
    }
    if(k < n)
        rollback(h, k, c);
}

signed main()
{
    clock_t a, b;
    cin >> n >> m;
    a = clock();
    MIN = f(n, m) + 1;
    solve(res, 0, 1, 0);
    b = clock();
    cout << "MIN = " << MIN << "\n";
    rollback(0, 0, 0);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            cout << setw(3) << solution[i][j];
        cout << "\n";
    }
    cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << "\n";
}