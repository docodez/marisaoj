#include <bits/stdc++.h>
using namespace std;

int n;
int a[11];

bool ok(int j, int i) {
	for (int k = 1; k < j; ++k) if (i == a[k] || abs(i - a[k]) == abs(j - k)) return false;
	return true;
}

int cnt = 0;
void go(int j) {
	if (j == n + 1) return void(++cnt);
	for (int i = 1; i <= n; ++i) if (ok(j, i)) {
		a[j] = i;
		go(j + 1);
	}
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n;
	go(1);
	cout << cnt;
	return 0;
}
