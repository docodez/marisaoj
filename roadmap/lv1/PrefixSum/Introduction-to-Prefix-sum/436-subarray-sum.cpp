#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n, x; cin >> n >> x;
	vector<long long> a(n + 1, 0);
	map<long long, int> cnt;
	long long ans = 0;
	cnt[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
		ans += cnt[a[i] - x];
		++cnt[a[i]];
//		cout << a[i] << ' ' << cnt[a[i] - x] << '\n';
	}
	cout << ans;
	return 0;
}
