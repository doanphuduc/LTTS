#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int s[N][N];

char a[N][N];

int sum(int x, int y, int u, int v) {
    return s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1];
}

bool ok(int l) {
    for (int i = 1; i <= n - l + 1; ++i) {
        for (int j = 1; j <= m - l + 1; ++j) if (sum(i, j, i + l - 1, j + l - 1) == l * l) {
            return true;
        }
    }
    return false;
}

int main() {
    // bài này trả về cạnh hình vuông max chứa toàn số 1. Thuật O(N ^ 2 log).

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j], s[i][j] = (a[i][j] == '1') + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
    int l = 1, r = min(n, m), f = 0;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (ok(m)) {
            f = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << f;
    // diện tích thì là cout << f * f;
    return 0;
}
