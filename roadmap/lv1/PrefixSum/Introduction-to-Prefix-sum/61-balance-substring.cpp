#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector<int> a(n + 1, 0);
	map<int, int> f;
	f[0] = 1;
	long long ans = 0;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0') a[i] = a[i - 1] - 1;
		else a[i] = a[i - 1] + 1;
		ans += f[a[i]];
		++f[a[i]];
	}
	cout << ans;
	return 0;
}
