#include <bits/stdc++.h>
using namespace std;

typedef array<array<int, 61>, 61> matrix;
matrix res;
int n, m, i, j;
int MIN, tp, cnt = 0;

void block(matrix a, int h, int k, int c)
{
    cout << cnt++ << ' ' << h << ' ' << k << ' ' << c << '\n';
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            cout << a[i][j] << " \n"[j == n];
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
    if(b == 0)
        return 0;
    return a / b + f(b, a % b);
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
    cout << "cnt = " << cnt << "\n";
    cout << double(b - a) / CLOCKS_PER_SEC << "\n";
}