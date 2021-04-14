#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

bool fre[N];

int main() {
    // Tested: https://www.spoj.com/problems/PRIME1/
    ios_base::sync_with_stdio(false);
    int TC; cin >> TC;
    while (TC--) {
        long long L, R; cin >> L >> R;
        memset(fre, false, sizeof fre);
        // fre[i - L] == false thì i là số nguyên tố.
        for (long long i = 2; i * i <= R; ++i) { // Chú ý: nếu sàng bình thường thì có check ở i, nhưng sàng này thì không.
            for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
                // Giải thích: j phải chạy từ i * i, hoặc số đầu tiên là bội của i mà >= L.
                fre[j - L] = true;
            }
        }
        if (1 >= L) fre[1 - L] = true;
        for (long long i = L; i <= R; ++i) if (!fre[i - L]) cout << i << "\n";
        cout << '\n';
    }
    return 0;
}

