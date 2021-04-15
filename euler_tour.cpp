#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int adj[N][N];

vector <int> p;

// Tested on: https://oj.vnoi.info/problem/nkpos

void dfs(int u) {
    for (int v = 1; v <= n; ++v) if (adj[u][v]) {
        adj[u][v]--; adj[v][u]--;
        dfs(v);
    }
    p.push_back(u);
}

int main() {
    // Điều kiện tồn tại chu trình euler: liên thông & mọi đỉnh đều bậc chẵn.
    // Điều kiện tồn tại đường đi euler: liên thông & có chính xác 2 đỉnh bậc lẻ
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int v; cin >> v; // trong bài nkpos dùng để test không cần quan tâm, nên chỉ đọc vào thôi.
    }
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u][v]++;
        adj[v][u]++;
    }
    // nếu là đường đi euler thì start tại đỉnh bậc lẻ.
    dfs(1);
    reverse(p.begin(), p.end());
    cout << p.size() - 1 << '\n';
    for (int u: p) cout << u << ' ';
    return 0;
} 