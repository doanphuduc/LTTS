#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int cnt_div[N], sum_div[N];

int main() {
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i) cnt_div[j]++, sum_div[j] += i;
    cout << cnt_div[20] << " " << sum_div[20] << '\n';
    return 0;
}
