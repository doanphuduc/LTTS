#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int ok[N], R[N];

int Right(int i) {
    return !ok[i] ? i : R[i] = Right(R[i]); // mọi ng có thể code if như này cho lẹ.
}

int Left(int i) {
    return !ok[i] ? i : L[i] = Left(L[i]);
}

int main() {
    // Ví dụ: Bài josephus.
    // ok[i] == false nếu thằng i chưa bị loại ra khỏi vòng tròn.
    // Hàm Right(i) tính thằng tiếp theo tính từ i mà ok[i] == false. Note: nếu ok[i] == false thì Right(i) = i.
    // Nếu trong một số bài cần hàm Left(i) thì sài.
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        R[i] = (i + 1) % n;
//        L[i] = (i - 1 + n) % n;
    }
    int p = 0;
    for (int i = 1; i < n; ++i) { // play n - 1 rounds
        for (int j = 1; j <= m; ++j) p = Right(R[p]); // quăng cây gậy m lần.
        // thằng p đã chết, gán ok[p] = true
        ok[p] = 1;

        // đưa cây gậy cho thằng tiếp theo.
        p = Right(R[p]);
    }
    cout << p + 1;
    return 0;
}
