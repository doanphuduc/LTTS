#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int B = 1e5 + 3;

// Tested: https://oj.vnoi.info/problem/paliny

int n;

char S[N];

long long pw[N];
long long H[2][N];

long long Hash(int k, int l, int r) {
    return H[k][r] - H[k][l - 1] * pw[r - l + 1];
}

bool Palin(int l, int r) {
    return Hash(0, l, r) == Hash(1, n - r + 1, n - l + 1);

}
 
int main() {
    cin >> n;
    string T; cin >> T;
    n = n * 2 + 1; 
    for (int i = 1; i <= n; ++i) 
        S[i] = (i & 1) ? '#' : T[i / 2 - 1]; // -1 do string T 0-indexed
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * B;
        H[0][i] = H[0][i - 1] * B + S[i];
        H[1][i] = H[1][i - 1] * B + S[n - i + 1];
        // cout << S[i];
    }
    // cout << '\n';
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = min(i, n - i + 1), f = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (Palin(i - m + 1, i + m - 1)) {
                f = m;
                l = m + 1;
            } else r = m - 1;
        }

        ans = max(ans, f);
    }
    cout << (2 * ans - 1) / 2;
    return 0;
}