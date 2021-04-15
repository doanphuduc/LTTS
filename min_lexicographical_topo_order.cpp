#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int deg[N];

vector <int> adj[N];

// tested: https://www.spoj.com/problems/TOPOSORT/

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    set <pair <int, int> > S;
    for (int i = 1; i <= n; ++i) S.insert({deg[i], i});
    vector <int> orders;
    bool fail = false;
    while (S.size()) {
        int d, u; tie(d, u) = *S.begin(); S.erase(S.begin());
        if (d != 0) {
            // xuất hiện chu trình
            fail = true;
            break;
        }
        orders.push_back(u);
        for (int v: adj[u]) {
            S.erase({deg[v], v});
            deg[v]--;
            S.insert({deg[v], v});
        }
    }
    if (fail) {
        cout << "Sandro fails.";
        return 0;
    }
    for (int u: orders) cout << u << " ";
    return 0;
}