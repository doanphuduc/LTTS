#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Edge {
    int u, v, w;
} E[N];

// Tested on: https://www.spoj.com/problems/MST/

int n, m;
int p[N];

int Root(int u) {
    return p[u] < 0 ? u : p[u] = Root(p[u]);
}

bool Union(int u, int v) {
    u = Root(u); v = Root(v);
    if (u == v) return false;
    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> E[i].u >> E[i].v >> E[i].w;
    sort(E + 1, E + m + 1, [&](Edge u, Edge v) {
        return u.w < v.w;
    }); // lambda function here
    long long ans = 0; // sum of weight can be long long
    memset(p, -1, sizeof p);
    for (int i = 1; i <= m; ++i) {
        if (Union(E[i].u, E[i].v)) ans += E[i].w;
    }
    cout << ans;

    return 0;
}