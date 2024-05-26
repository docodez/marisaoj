#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n, m, q; cin >> n >> m >> q;
	vector<vector<long long> > a(n + 1, vector<long long>(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	for (int x, y, z, t; q--; ) {
		cin >> x >> y >> z >> t;
		cout << a[z][t] - a[x - 1][t] - a[z][y - 1] + a[x - 1][y - 1] << '\n';
	}
	return 0;
}
