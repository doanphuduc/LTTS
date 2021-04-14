#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;

bool fre[N];

vector <int> adj[N];

int cmp = 0;

void dfs(int u) {
    fre[u] = true;
    for (int v: adj[u]) if (!fre[v]) dfs(v);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); // nếu cạnh có hướng
        adj[v].push_back(u); // push thêm nếu cạnh vô hướng
    }
    cmp = 0;
    for (int i = 1; i <= n; ++i) if (!fre[i]) {
        dfs(i);
        ++cmp;
    }
    cout << cmp << '\n';
    return 0;
}
