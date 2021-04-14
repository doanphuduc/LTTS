#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int d[N][N];

char S[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> S[i][j];
    queue <pair <int, int> > Q;
    auto Inside = [](int x, int y) {
        return 1 <= x && x <= n && 1 <= y && y <= m;
    };
    int dx[] = {0, -1, +1, 0};
    int dy[] = {1, 0, 0, -1}; // nhớ hai mảng này, cách nhớ là 2 số 0 đi với +-1
    // Nếu 8 hướng sẽ là: (Cách nhớ sẽ là 4 hướng và +-1 kết hợp với nhau thành 4 hướng nữa.
//    int dx[] = {0, -1, +1, 0, -1, +1, -1, +1};
//    int dy[] = {+1, 0, 0, -1, -1, +1, +1, -1};

    memset(d, -1, sizeof d);
    Q.push({1, 1}); d[1][1] = 0;
    while (Q.size()) {
        int x, y; // nhớ khai báo trước khi dùng tie.
        tie(x, y) = Q.front(); Q.pop(); // dùng tie để lấy nhanh first và second.
        for (int k = 0; k < 4; ++k) {
            int u = x + dx[k], v = y + dy[k];
            if (Inside(u, v) && S[u][v] == '.' && d[u][v] == -1) {
                d[u][v] = d[x][y] + 1;
                Q.push({u, v});
            }
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}

