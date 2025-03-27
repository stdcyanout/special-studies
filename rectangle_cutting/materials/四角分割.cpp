#include <bits/stdc++.h>
using namespace std;

int F (int n, int m) {
    if (m == 0) return 0;
    return n / m + F(m, n % m);
}

int G (int n, int m) {
    if (n < m) swap(n, m);
    int k = n - m;
    int ret = F(n, m);
    for (int a = 0; a <= k; a++) {
        if ((n - a) % (2 * k) == 0) {
            int x = (n - a) / (2 * k);
            ret = min(ret, 4 + F(x - 1, 2) + F(a, k - a));
        }
    }
    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << G(n, m) << "\n";
}