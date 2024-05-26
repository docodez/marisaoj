#include <bits/stdc++.h>
using namespace std;

void sol() {
	int n, q; cin >> n >> q;
	vector<long long> d(n + 5, 0), e(n + 5, 0);
	while (q--) {
		int l, r; cin >> l >> r;
		d[l]++;
		d[r + 1]--;
		e[r + 1] -= (r - l + 1);
	}
	long long t = 0;
	for (int i = 1; i <= n; ++i) {
		d[i] += d[i - 1];
		t += d[i] + e[i];
		cout << t << ' ';
	}
}

int main() {
	ios::sync_with_stdio(NULL);	cin.tie(0);
	int t = 1;
  // cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}
