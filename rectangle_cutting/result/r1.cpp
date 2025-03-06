#include <bits/stdc++.h>
using namespace std;

int gcd (int n, int m) {
    if (m == 0) return 0;
    return n / m + gcd(m, n % m);
}

int main() {
    int n, m;
    clock_t a, b;
    cin >> n >> m;
    a = clock();
    int ret = gcd(n, m);
    b = clock();
    cout << ret << endl;
    cout << fixed << setprecision(6) << double(b - a) / CLOCKS_PER_SEC << endl;
}