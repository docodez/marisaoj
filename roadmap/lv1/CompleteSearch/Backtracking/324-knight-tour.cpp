#include <bits/stdc++.h>
using namespace std;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
int a[8][8];

bool ok(int x, int y) {
	return (0 < x && x <= n && 0 < y && y <= m && !a[x][y]);
}

bool go(int x, int y, int cnt) {
	a[x][y] = cnt;
	if (cnt == n * m) return true;
	for (int i = 0; i < 8; ++i) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (!ok(X, Y)) continue;
		if (go(X, Y, cnt + 1)) return true;
		a[X][Y] = 0;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> m;
	go(1, 1, 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cout << a[i][j] << " \n"[j == m];
	}
	return 0;
}
