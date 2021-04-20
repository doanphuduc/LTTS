#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int ans[N];

pair <double, double> a[N];
double b[N];
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; ++i) {
        double l, r; tie(l, r) = a[i];
        if (l <= r) {
            int x = lower_bound(b + 1, b + m + 1, l) - b; // thang dau tien >= l
            int y = upper_bound(b + 1, b + m + 1, r) - b - 1; // thang cuoi cung <= r ((se bang thang dau tien > r) - 1)
            ans[x]++; ans[y + 1]--;
        } else {
            int x = upper_bound(b + 1, b + m + 1, l) - b - 1; // thang cuoi cung <= l
            ans[1]++; ans[x + 1]--;
                x = lower_bound(b + 1, b + m + 1, r) - b;
            ans[x]++; ans[n + 1]--;
        }
    }
    for (int i = 1; i <= n; ++i) ans[i] += ans[i - 1];
    int mx = *max_element(ans + 1, ans + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += (ans[i] == mx);
    cout << mx << ' ' << cnt << '\n';
    return 0;
}