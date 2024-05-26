#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n; cin >> n;
	pair<int, int> a[15];
	for (int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;

	long long ans = 1e10 + 10;
	vector<int> p(n, 0);
	pair<int, int> d[15];
	iota(p.begin(), p.end(), 1);
	do {
		for (int i = 0; i < n; ++i) d[i + 1] = a[p[i]];
		long long total = 0;
		for (int i = 1; i <= n; ++i) {
			total += d[i].first + d[i].second;
			int t = d[i].second;
			for (int j = i + 1; j <= n && t > 0; ++j) {
				t -= d[j].first;
				d[j].first = max(-t, 0);
			}
		}
		ans = min(ans, total);
	} while (next_permutation(p.begin(), p.end()));
	cout << ans;
	return 0;
}
