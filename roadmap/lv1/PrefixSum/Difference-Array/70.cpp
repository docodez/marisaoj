#include <bits/stdc++.h>
using namespace std;

void sol() {
	int n, q, m; cin >> n >> q >> m;
	vector<long long> d(n + 5, 0), qq(q + 5, 0);
	vector<pair<int, int> > Q(q + 5);
	for (int i = 1; i <= q; ++i) cin >> Q[i].first >> Q[i].second;
	for (int l, r, i = 1; i <= m; ++i) {
		cin >> l >> r;
		qq[l]++;
		qq[r + 1]--;
	}
	for (int i = 1; i <= q; ++i) {
		qq[i] += qq[i - 1];
		d[Q[i].first] += qq[i];
		d[Q[i].second + 1] -= qq[i];
	}
	for (int i = 1; i <= n; ++i) {
		d[i] += d[i - 1];
		cout << d[i] << ' ';
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
