#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;

int n, m;
int a[N][N], s[N][N];

int sum(int x, int y, int u, int v) {
    return s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1];
    // cách nhớ: 2 chỉ số dưới của hình chữ nhât lần lượt bị trừ 1. (x - 1, v), (u, y - 1), (x - 1, y - 1).
}

int main()  {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; // nhớ công thức này luôn.
        }
    }
    cout << sum(1, 1, 2, 3);
    return 0;
}
