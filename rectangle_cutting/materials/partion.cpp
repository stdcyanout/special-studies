#include <bits/stdc++.h>
using namespace std;

typedef array<array<int, 41>, 41> matrix;
matrix ta;
int n, m, i, j;
int MIN, tp;

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
            {
                if(c < MIN)
                {
                    MIN = c;
                    ta = a;
                }
            }
        }
    }
}

int f(int a, int b)
{
    int q, r, sum;
    sum = 0;
    while(b != 0)
    {
        q = a / b;
        r = a % b;
        sum = sum + q;
        a = b;
        b = r;
    }
    return sum;
}

signed main()
{
    matrix a;
    cin >> n >> m;
    for(j = 1; j <= n; j++)
        for(i = 1; i <= m; i++)
            a[i][j] = 0;
    tp = f(n, m);
    cout << "F = " << tp << "\n";
    MIN = tp;
    block(a, 1, 1, 0);
    if(MIN == tp)
        cout << "NEVER BETTER\n";
    else
    {
        cout << "MIN = " << MIN << "\n";
        cout << "THE MATRIX IS\n";
        for(j = 1; j <= n; j++)
        {
            for(i = 1; i <= m; i++)
                cout << setw(3) << ta[i][j];
            cout << "\n";
        }
    }
}