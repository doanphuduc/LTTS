#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6;
const long long B = 1e5+3;
const long long BASE = 1e9 + 21;
 
int n;
string s;
char a[N];
long long H[2][N], pw[N];
 
long long Hash(int k, int l, int r)
{
	return (H[k][r] - H[k][l-1] * pw[r - l + 1] + BASE * BASE) % BASE;
}
 
bool Palind(int i, int d)
{
	int l = i - d + 1;
	int r = i + d - 1;
	return Hash(0, l, r) == Hash(1, n - r + 1, n - l + 1);
}
 
int main()
{
	cin >> n;
	cin >> s;
	n = 2 * n + 1;
	for(int i = 1; i <= n; ++i)
	{
		a[i] = i & 1 ? '#' : s[i / 2 - 1];
	}
 
	pw[0] = 1;
	for(int i = 1; i <= n; ++i) pw[i] = pw[i-1] * B % BASE;
 
	for(int i = 1; i <= n; ++i)
	{
		H[0][i] = (H[0][i-1] * B + a[i]) % BASE;
		H[1][i] = (H[1][i-1] * B + a[n-i+1]) % BASE;
	}
 
	int res = 1;
	for(int i = 1; i <= n; ++i)
	{
		while(res + 1 <= min(i, n - i + 1) && Palind(i, res + 1)) res++;
	}
	cout << (2 * res - 1) / 2 << '\n';
}