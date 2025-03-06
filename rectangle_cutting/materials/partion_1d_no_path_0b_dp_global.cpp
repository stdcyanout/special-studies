#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef array<int, 41> arr;
arr res;
int n, m, MIN;
int dp[41][41];
arr a;

template <class ...T> void debug(T ...args)
{
    int cnt = sizeof...(T);
    ((cerr << "\e[1;31m"), ..., (cerr << args << (--cnt ? " " : "\e[0m\n")));
}
template <class T> void orange(T L, T R)
{
    cerr << "\e[1;33m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

void solve(int h, int k, int c)
{
    // orange(a.begin(), a.begin() + 13);
    int l, i;
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
                solve(h + l, k, c);
            else
            {
                int hp = min_element(a.begin(), a.begin() + m) - a.begin();
                int kp = a[hp] + 1;
                if(kp <= n)
                    solve(hp, kp, c);
                else
                    MIN = min(c, MIN);
                for(i = 0; i < l; i++)
                    a[h + i] -= l;
                return;
            }
            for(i = 0; i < l; i++)
                a[h + i] -= l;
        }
    }
}

int f(int a, int b)
{
    int i, j, k;
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
    solve(0, 1, 0);
    b = clock();
    cout << "MIN = " << MIN << "\n";
    cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << "\n";
}