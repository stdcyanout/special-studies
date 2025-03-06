#include <bits/stdc++.h>
using namespace std;

typedef array<int, 31> arr;
arr res;
int n, m, i, j;
int MIN, tp;

void block(arr a, int h, int k, int c)
{
    int l;
    c = c + 1;
    if(c < MIN)
    {
        l = 0;
        while(h + l < m && k + l <= n && a[h] >= a[h + l])
        {
            assert(a[h] == a[h + l]); // never fail
            l = l + 1;
            for(i = 0; i < l; i++)
                a[h + i] += l;
            if(h + l < m && a[h] - l >= a[h + l])
                block(a, h + l, k, c);
            else
            {
                h = min_element(a.begin(), a.begin() + m) - a.begin();
                k = a[h] + 1;
                if(k <= n)
                    block(a, h, k, c);
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
    block(res, 0, 1, 0);
    b = clock();
    cout << "MIN = " << MIN << "\n";
    cout << double(b - a) / CLOCKS_PER_SEC << "\n";
}