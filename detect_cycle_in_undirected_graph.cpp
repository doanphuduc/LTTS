#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, q;
int p[N], col[N];

vector <int> adj[N];

bool found = false;
vector <int> cycle;

void dfs(int u) {
    col[u] = 1;
    for (int v: adj[u]) {
        if (v == p[u]) continue; // điều khác biệt so với directed graph.
        if (col[v] == 1) {
            // found cycle
            found = true;
            // nếu cần in ra chu trình bất kỳ thì dùng code ở dưới.
            cycle.clear();
            int t = u;
            while (t != v) {
                cycle.push_back(t);
                t = p[t];
            }
            cycle.push_back(t);
        }
        if (col[v] == 0) {
            p[v] = u;
            dfs(v);
        }
    }
    col[u] = 2;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) if (col[i] == 0) dfs(i);
    if (found) {
        cout << "Cycle: ";
        for (int u: cycle) cout << u << " "; cout << '\n';
    } else {
        cout << "No Cycle\n";
    }
    return 0;
}