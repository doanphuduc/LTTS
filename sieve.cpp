#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

bool fre[N];

int main() {
    int L, R; cin >> L >> R;
    fre[0] = fre[1] = true; // take care this corner case.
    for (int i = 2; 1LL * i * i < N; ++i) if (fre[i] == false) {
        for (long long j = 1LL * i * i; j < N; j += i) fre[j] = true;
    }
    for (int i = L; i <= R; ++i) if (!fre[i]) cout << i << '\n';
    return 0;
}

