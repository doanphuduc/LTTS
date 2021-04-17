#include <bits/stdc++.h>

using namespace std;

map <pair <long long, int>, int> cnt;

const int B = 1e5 + 7;
const int BASE = 1e9 + 13;

// pair <long long, int> chứa hash 2 base, long long là hash tràn, int là hash mod BASE

pair <long long, int> Hash(string &s) {
    pair <long long, int> h;
    for (char c: s) {
        h.first = h.first * B + c - 'a' + 1; // + 1 để tránh trường hợp hash của aa = hash của a.
        h.second = (h.second * B + c - 'a' + 1) % BASE;
    } 
    return h;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        pair <long long, int> h = {0, 0};
        string s; cin >> s;
        string r;
        pair <long long, int> h;
        for (char c: s) {
            h.first = h.first * B + c - 'a' + 1; // + 1 để tránh trường hợp hash của aa = hash của a.
            h.second = (h.second * B + c - 'a' + 1) % BASE;
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