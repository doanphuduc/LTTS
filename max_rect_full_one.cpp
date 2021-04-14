#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int p[N];
int c[N][N];

char s[N][N];

int main() {
    // bài này trả về hình chữ nhật có diện tích lớn nhất chứa toàn số 1. Thuật O(N ^ 3).
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> s[i][j], c[i][j] = c[i - 1][j] + (s[i][j] == '1');
    }

    // c[i][j] là prefix sum theo cột.
    int ans = 0;
    for (int i = 1; i <= n; ++i) { // for cố định 2 hàng
        for (int j = i; j <= n; ++j) {
            for (int k = 1; k <= m; ++k) p[k] = (c[j][k] - c[i - 1][k] == j - i + 1); // đưa bài toán 2D về thành 1D.
            // vòng for này tìm dãy array 1D dài nhất (như cách code subarray team hay code).
            for (int k = 1; k <= m; ++k) if (p[k] == 1) {
                int t = k;
                while (t <= m && p[t] == 1) ++t;
                ans = max(ans, (t - k) * (j - i + 1));
                k = t - 1;
            }
        }
    }
    cout << ans;
    return 0;
}
