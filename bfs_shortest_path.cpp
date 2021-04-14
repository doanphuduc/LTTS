#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int d[N];

vector <int> adj[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d, -1, sizeof d); // nhớ memset -1
    queue <int> Q;
    int source = 1; // source is first vertex
    d[source] = 0; Q.push(source);
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        for (int v: adj[u]) if (d[v] == -1) d[v] = d[u] + 1, Q.push(v); // mọi ng có thể nhớ cách code dùng dấu , để code cho nhanh.
    }
    int dest = n; // destination is n-th vertex
    cout << d[dest] << '\n';
    return 0;
}
