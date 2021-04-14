#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int a[N][N], dp[N][N];

// Tested on: https://www.codechef.com/problems/SUBMAT

int main() {
    int TC; cin >> TC;
    while (TC--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) cin >> a[i][j];
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                if (a[i][j] == 1) a[i][j] = min({a[i - 1][j], a[i - 1][j - 1], a[i][j - 1]}) + 1;
                else a[i][j] = 0;
                ans = max(ans, a[i][j]);
            }
        }
        cout << ans << '\n';

    }
    return 0;
}

