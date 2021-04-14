#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, s, t;

int d[N];

vector <pair <int, int> > adj[N];

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    set <pair <int, int> > S;
    for (int i = 1; i <= n; ++i) d[i] = (int)1e9; // nhớ khởi tạo inf.
    d[s] = 0; S.insert({d[s], s});
    while (S.size()) {
        int u = S.begin() -> second; S.erase(S.begin());
        for (auto pp: adj[u]) {
            int v = pp.first, w = pp.second; // cứ gán để tránh code phức tạp.
            if (d[v] > d[u] + w) {
                S.erase({d[v], v});
                d[v] = d[u] + w;
                S.insert({d[v], v});
            }
        }
    }
    cout << (d[t] >= (int)1e9 ? -1 : d[t]); // nhớ cách này để in ra -1 cho ez.

    return 0;
}
