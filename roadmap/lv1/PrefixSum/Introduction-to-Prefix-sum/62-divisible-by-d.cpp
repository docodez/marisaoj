#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n, d;	cin >> n >> d;
	vector<int> a(n + 1, 0);
	map<int, int> cnt;
	long long ans = 0;
	cnt[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = (a[i - 1] + (((a[i] % d) + 1ll * d * d) % d)) % d;

		ans += cnt[a[i]];
		++cnt[a[i]];
	}
	cout << ans;
	return 0;
}
