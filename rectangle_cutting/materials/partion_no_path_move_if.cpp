#include <bits/stdc++.h>
using namespace std;

typedef array<array<int, 21>, 21> matrix;
matrix res;
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
            else
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
                return;
            }
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
    cin >> n >> m;
    tp = f(n, m);
    cout << "F = " << tp << "\n";
    MIN = tp;
    block(res, 1, 1, 0);
    cout << "MIN = " << MIN << "\n";
}