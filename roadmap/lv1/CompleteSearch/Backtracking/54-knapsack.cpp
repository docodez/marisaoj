#include <bits/stdc++.h>
using namespace std;

int n, S;
int w[22], v[22];

long long ans = 0;
void go(int j, long long s, long long V) {
	ans = max(ans, V);
	for (int i = j + 1; i <= n; ++i) {
		if (s + w[i] <= S) go(i, s + w[i], V + v[i]);
	}
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
	go(0, 0, 0);
	cout << ans;
	return 0;
}
