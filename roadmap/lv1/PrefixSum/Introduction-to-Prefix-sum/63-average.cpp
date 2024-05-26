#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n, k;	cin >> n >> k;
	long long sum = 0, ans = 0;
	map<long long, int> cnt;
	cnt[0] = 1;
	for (int x, i = 1; i <= n; ++i) {
		cin >> x;
		sum += x - k;
		ans += cnt[sum];
		++cnt[sum];
	}
	cout << ans;
	return 0;
}
