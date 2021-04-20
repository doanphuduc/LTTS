// Tested: https://oj.vnoi.info/problem/qbrect

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int a[N][N];

int f[N], L[N], R[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) 
            f[j] = a[i][j] == 0 ? 0 : f[j] + 1;
        stack <int> ST;
        for (int j = 1; j <= m; ++j) {
            while (ST.size() && f[ST.top()] >= f[j]) ST.pop(); // do tim min nen nhung thang >= thang hien tai thi bo di
            L[j] = ST.size() == 0 ? 1 : ST.top() + 1;
            ST.push(j);
        }
        while (ST.size()) ST.pop(); // nho remove, vi o dang truoc co the con gia tri

        for (int j = m; j >= 1; --j) {
            while (ST.size() && f[ST.top()] >= f[j]) ST.pop();
            R[j] = ST.size() == 0 ? m : ST.top() - 1;
            ST.push(j);
        }
        for (int j = 1; j <= m; ++j) ans = max(ans, f[j] * (R[j] - L[j] + 1));
    }
    cout << ans;
    return 0;
}