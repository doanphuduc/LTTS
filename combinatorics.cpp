#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int c[N][N];

int C(int k, int n) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (c[k][n] != -1) return c[k][n];
    return c[k][n] = C(k, n - 1) + C(k - 1, n - 1); // Hạ chỉ số dưới.
}

int fact[N];

int main() {
    // C(k, n)
    memset(c, -1, sizeof c); // nhớ memset -1
    cout << C(10, 20) << '\n';

    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i;
    // A(k, n) = C(k, n) * fact[k]
    cout << C(2, 3) * 2 << '\n';


    return 0;
}
