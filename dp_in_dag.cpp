#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int deg[N], a[N];

long long dp[N];

vector <int> adj[N];

int main() {
    int TC = 1;
    while (TC--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) adj[i].clear(), deg[i] = 0;
        for (int i = 1; i <= n; ++i) dp[i] = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            cout << u <<  " " << v << '\n';
            adj[u].push_back(v); deg[v]++;
        }

        vector <int> orders;
        set <pair <int, int> > S;
        for (int i = 1; i <= n; ++i) S.insert({deg[i], i});
        while (S.size()) {
            int u = S.begin() -> second; S.erase(S.begin());
            orders.push_back(u);
            for (int v: adj[u]) {
                S.erase({deg[v], v});
                deg[v]--;
                S.insert({deg[v], v});
            }
        }
        reverse(orders.begin(), orders.end());
        dp[n] = 1;
        for (int u: orders) {
            for (int v: adj[u]) dp[u] += dp[v];
        }
        for (int i = 1; i <= n; ++i) cout << dp[i] << ' ';
        cout << '\n';
    }

    return 0;
}