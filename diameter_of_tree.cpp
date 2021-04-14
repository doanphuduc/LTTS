#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;

vector <int> adj[N];

pair <int, int> dfs(int u, int par = -1, int depth = 0) {
    pair <int, int> ans = {depth, u};
    for (int v: adj[u]) if (v != par) ans = max(ans, dfs(v, u, depth + 1));
    return ans;
}

int main() {
    cin >> n;
    for (int i =1 ; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair <int, int> f = dfs(1); // (max depth, node)
                    f = dfs(f.second); // dfs from farthest node
    cout << f.first;
    return 0;
}
