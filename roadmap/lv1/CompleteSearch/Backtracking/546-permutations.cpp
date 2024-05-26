#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10];
bool b[10];

void go(int t) {
	if (t > k) {
		for (int i = 1; i <= k; ++i) cout << a[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; ++i) if (!b[i]) {
		b[i] = true;
		a[t] = i;
		go (t + 1);
		b[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> k;
	go(1);
	return 0;
}
