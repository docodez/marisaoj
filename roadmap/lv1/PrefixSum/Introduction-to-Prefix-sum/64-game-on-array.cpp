#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
	int ans = -1e9 + 7;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, abs(a[i - 1] * 1 + (a[n] - a[i - 1]) * -1));
	}
	cout << ans;
	return 0;
}
