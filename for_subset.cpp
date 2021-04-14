#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int mask = 0; mask < (1 << n); ++mask) {
        // do sth with subset
        int s = 0;
        for (int i = 1; i <= n; ++i) if (mask >> (i - 1) & 1) { // (i - 1) nếu mảng index từ 1, i nếu mảng index từ 0.
            // i-th element in subset
            s += a[i];
        }
        ans = max(ans, s);
    }
    cout << ans;

    return 0;
}
