#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[22][22], b[22][22];
bool vis[22][22];

int dx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dy[] = {-1, 0, +1, -1, +1, -1, 0, +1};

bool check() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] != 0) return false;
		}
	}

	return true;
}

bool ok(int x, int y) {
	if (0 < x && x <= n && 0 < y && y <= m) return true;
	return false;
}

bool go() {
	if (check()) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << b[i][j] << ' ';
			}
			cout << '\n';
		}
		return true;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (!vis[i][j]) {
			vis[i][j] = true;
			bool has = true;
			for (int t = 0; t < 8; ++t) if (ok(i + dx[t], j + dy[t])) {
				if (!(a[i + dx[t]][j + dy[t]])) has = false;
				a[i + dx[t]][j + dy[t]] -= 1;
			}
			if (has) {
				b[i][j] = 1;
				if (go())	return true;
			}
			for (int t = 0; t < 8; ++t) {
				a[i + dx[t]][j + dy[t]] += 1;
			}
			if (!has) {
				b[i][j] = 0;
				if (go()) return true;
			}
			vis[i][j] = false;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	go();
	return 0;
}
