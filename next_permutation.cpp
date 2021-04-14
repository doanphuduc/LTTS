#include <bits/stdc++.h>

using namespace std;


const int N = 1e3 + 10;

pair <int, int> a[N];
pair <int, int> b[N];

int sqr(int x) {
    return x * x;
}

int Dist(pair <int, int> A, pair <int, int> B) {
    return sqr(A.first - B.first) + sqr(A.second - B.second);
}

bool ok() {
    int d = Dist(b[0], b[1]);
    for (int i = 0; i < 4; ++i) if (Dist(b[i], b[(i + 1) % 4]) != d) return false;
    return Dist(b[0], b[1]) + Dist(b[0], b[3]) == Dist(b[1], b[3]);
}

void Solve() {
    vector <int> per;
    for (int i = 0; i < 4; ++i) per.push_back(i);
    do {
        for (int i = 0; i < 4; ++i) b[i] = a[per[i]];
        if (ok()) {
            cout << "YES\n";
            return;
        }
    } while (next_permutation(per.begin(), per.end()));
    cout << "NO\n";
}

int main() {

    // ví dụ bài check hình vuông ABCD nếu có thứ tự.
    int TC;
    cin >> TC;
    while (TC--) {
        for (int i = 0; i < 4; ++i) cin >> a[i].first >> a[i].second;
        Solve();
    }
    return 0;
}

