#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 10;

int TSize = 0;
int cnt[N];
int e[N][26];

int main() {
    int n; cin >> n;
    memset(e, -1, sizeof e);
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        int p = 0;
        for (char ch: s) {
            int c = ch - 'a';
            if (e[p][c] == -1) e[p][c] = ++TSize;
            p = e[p][c];
            cnt[p]++;
        }
    }
    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int p = 0;
        for (char ch: t) {
            int c = ch - 'a';
            if (p != -1) p = e[p][c];
        }
        cout << (p == -1 ? 0 : cnt[p]) << '\n';

    }
    return 0;
}