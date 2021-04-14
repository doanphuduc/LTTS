#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int s[N];
int c[N][N];
int a[N][N];

int main() {
    // bài này trả về hình chữ nhật có diện tích tổng trọng số lớn nhất. Thuật O(N ^ 3).
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j], c[i][j] = c[i - 1][j] + a[i][j];
    }

    // c[i][j] là prefix sum theo cột.
    int ans = 0;
    for (int i = 1; i <= n; ++i) { // for cố định 2 hàng
        for (int j = i; j <= n; ++j) {
            for (int k = 1; k <= m; ++k) s[k] = c[j][k] - c[i - 1][k], s[k] += s[k - 1]; // đưa bài toán 2D về thành 1D, tính prefix_sum
            // vòng for này tìm dãy array 1D có max trọng số.
            int mn = 0;
            for (int k = 1; k <= m; ++k) {
                ans = max(ans, s[k] - mn);
                mn = min(mn, s[k]);
            }
        }
    }
    cout << ans;
    return 0;
}

