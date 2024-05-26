#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int x, y; cin >> x >> y;
	string s;	cin >> s;

	long long sum = 0, ans = 0;
	map<long long, int> cnt;
	cnt[0] = 1;
	for (char &ch : s) {
		if (ch == '0') {
			sum -= y;
		} else {
			sum += x;
		}
		ans += cnt[sum];
		++cnt[sum];
	}
	cout << ans;
	return 0;
}
