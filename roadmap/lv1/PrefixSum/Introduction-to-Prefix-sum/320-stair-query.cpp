#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n, q;
long long a[maxn];
long long b[maxn], p[maxn], s[maxn];

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = n; i >= 1; --i) {
		b[i] = b[i + 1] + a[i];
		p[i] = p[i + 1] + b[i];
		s[i] = s[i + 1] + a[i] * i;
	}
	for (int l, r; q--; ) {
		cin >> l >> r;
		cout << p[l] - s[r + 1] + b[r + 1] * (l - 1) << '\n';
	}
	return 0;
}
