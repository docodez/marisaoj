#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, q;
long long a[maxn];

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
	while (q--) {
		int l, r; cin >> l >> r;
		cout << a[r] - a[l - 1] << '\n';
	}
	return 0;
}
