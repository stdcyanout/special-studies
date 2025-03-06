#include <bits/stdc++.h>
using namespace std;

typedef array<array<int, 41>, 41> matrix;
matrix res;
int n, m, i, j;
int MIN, tp;
int dp[41][41];

void block(matrix a, int h, int k, int c)
{
    int l;
    c = c + 1;
    if(c < MIN)
    {
        l = 0;
        while(h + l <= m && k + l <= n && a[h + l][k] == 0)
        {
            l = l + 1;
            for(i = 0; i < l; i++)
                for(j = 0; j < l; j++)
                    a[h + i][k + j] = l;
            if(h + l <= m && a[h + l][k] == 0)
                block(a, h + l, k, c);
        }
        if(h + l == m + 1 || a[h + l][k] != 0)
        {
            while(a[h][k] != 0 && k <= n)
            {
                h = h + a[h][k];
                if(h == m + 1)
                {
                    h = 1;
                    k = k + 1;
                }
            }
            if(k <= n)
                block(a, h, k, c);
            else
                MIN = min(c, MIN);
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
    tp = f(n, m);
    cout << "F = " << tp << "\n";
    MIN = tp;
    a = clock();
    block(res, 1, 1, 0);
    b = clock();
    cout << "MIN = " << MIN << "\n";
    cout << double(b - a) / CLOCKS_PER_SEC << "\n";
}