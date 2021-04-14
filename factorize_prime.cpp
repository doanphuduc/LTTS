#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int pr[N];

vector <pair <int, int> > fact(int n) {
    vector <pair <int, int> > ans;
    // do pr[N] là ước nhỏ nhất của N rồi nên không cần sort p lại.
    int pd = -1, cnt = 0;
    while (n > 1) {
        int d = pr[n];
        if (d == pd) {
            ++cnt;
        } else {
            if (cnt) ans.push_back({pd, cnt});
            pd = d;
            cnt = 1;
        }
        n /= d;
    }

    if (cnt) ans.push_back({pd, cnt});

    return ans;
}

int main() {
    int n; cin >> n;
    for (int i = 2; 1LL * i * i < N; ++i) if (pr[i] == 0) {
        for (long long j = 1LL * i * i; j < N; j += i)
            if (pr[j] == 0) pr[j] = i;
    }
    for (int i = 1; i < N; ++i) if (pr[i] == 0) pr[i] = i; // take care here
//    cout << pr[10] << '\n';
    auto vec = fact(n);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i].first;
        if (vec[i].second > 1) cout << "^" << vec[i].second;
//        cout << "* "[i == vec.size() - 1];
        if (i != vec.size() - 1) cout << "*";
    }
    return 0;
}

