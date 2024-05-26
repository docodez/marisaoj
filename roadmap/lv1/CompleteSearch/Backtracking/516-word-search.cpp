#include <bits/stdc++.h>
using namespace std;

int n, m;
string a[10];
bool vis[10][10];
string s;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool go(int x, int y, string str) {
	vis[x][y] = true;
	if (str.size() >= s.size()) {
		if (str == s) return true;
		return false;
	}
	for (int d = 0; d < 4; ++d) {
		int X = x + dx[d];
		int Y = y + dy[d];
		if (0 < X && X <= n && 0 < Y && Y <= m && !vis[X][Y]) {
			if (go(X, Y, str + a[X][Y])) return true;
			vis[X][Y] = false;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = " " + a[i];
	}
	cin >> s;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (a[i][j] == s[0]) {
			if (go(i, j, a[i].substr(j, 1))) return cout << "YES", 0;
		}
	}
	cout << "NO";
	return 0;
}
