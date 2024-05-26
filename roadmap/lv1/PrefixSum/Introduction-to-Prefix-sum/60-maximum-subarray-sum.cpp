#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n;
long long a[maxn];
long long ans = -1e15, mn = 0;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
		ans = max(ans, a[i] - mn);
		mn = min(mn, a[i]);
	}
	cout << ans;
	return 0;
}
