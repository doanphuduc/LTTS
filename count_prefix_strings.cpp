#include <bits/stdc++.h>

using namespace std;

map <long long, int> cnt;

const int B = 1e5 + 7;

long long Hash(string &s) {
    long long h = 0;
    for (char c: s) h = h * B + c;
    return h;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        long long h = 0;
        for (char c: s) {
            h = h * B + c;
            cnt[h]++;
        }
    }
    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        cout << cnt[Hash(t)] << '\n';
    }
    return 0;
}