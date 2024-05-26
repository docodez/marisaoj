#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a[10], b[10], c[10];
int A[10];

int cnt = 0;
void check() {
	for (int i = 0; i < q; ++i) if (A[a[i]] + A[b[i]] != c[i]) return;
	++cnt;
}

void go(int j) {
	if (j == n + 1) check();
	else
	for (int i = 1; i <= m; ++i) {
		A[j] = i;
		go(j + 1);
	}
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < q; ++i) cin >> a[i] >> b[i] >> c[i];
	go(1);
	cout << cnt;
	return 0;
}
