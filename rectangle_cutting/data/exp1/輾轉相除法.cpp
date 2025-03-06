#include <bits/stdc++.h>
using namespace std;

int gcd (int n, int m) {
    if (m == 0) return 0;
    return n / m + gcd(m, n % m);
}

int main() {
    freopen("輾轉相除法.txt", "w", stdout);
    int n, m;
    for (n = 1; n <= 30; n++) {
        for (m = 1; m <= n; m++) {
            int ret = gcd(n, m);
            cout << ret << endl;
        }
    }
}