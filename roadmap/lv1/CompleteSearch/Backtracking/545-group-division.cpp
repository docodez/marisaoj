#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[15], cho[15];
int s[15];
int ms;

bool go(int t) {
	if (s[t] == ms) {
		if (t == 1) {
			for (int i = 1; i <= n; ++i) cout << cho[i] << ' ';
			return true;
		}
		--t;
	}
	for (int i = 1; i <= n; ++i) if (!cho[i] && a[i] + s[t] <= ms) {
		cho[i] = t;
		s[t] += a[i];
		if (go(t)) return true;
		s[t] -= a[i];
		cho[i] = 0;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> k;
	int total = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i], total += a[i];
	if (total % k != 0) return cout << "ze", 0;
	ms = total / k;
	if (!go(k)) cout << "ze";
	return 0;
}
