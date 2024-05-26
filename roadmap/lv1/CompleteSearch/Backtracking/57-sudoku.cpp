#include <bits/stdc++.h>
using namespace std;

string s = "123456789";

int a[10][10];
vector<pair<int, int> > v;

bool check() {
	for (int i = 1; i <= 9; i += 3) {
		for (int j = 1; j <= 9; j += 3) {
			string S = "";
			for (int h = 0; h < 3; ++h) {
				for (int k = 0; k < 3; ++k) {
					S = S + to_string(a[i + h][j + k]);
				}
			}
			sort(S.begin(), S.end());
			if (S != s) return false;
		}
	}
	return true;
}

bool ok(int x, int y, int k) {
	for (int i = 1; i <= 9; ++i) {
		if (a[x][i] == k || a[i][y] == k) return false;
	}
	int xx = (x - 1) / 3, yy = (y - 1) / 3;
	for (int i = 3 * xx + 1; i <= 3 * xx + 3; ++i) {
		for (int j = 3 * yy + 1; j <= 3 * yy + 3; ++j) {
			if (a[i][j] == k) return false;
		}
	}
	return true;
}

bool go(int i) {
	if (i == v.size()) {
		 return check();
	}
	for (int k = 1; k <= 9; ++k) if (ok(v[i].first, v[i].second, k)) {
		a[v[i].first][v[i].second] = k;
		if (go(i + 1)) return true;
		a[v[i].first][v[i].second] = 0;
	}
	return false;
}

int main() {
	#define taskname "sudoku"
	freopen (taskname".inp", "r", stdin);
	freopen (taskname".out", "w", stdout);
	ios::sync_with_stdio(NULL); cin.tie(0);
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) v.push_back({i, j});
		}
	}
	go(0);
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
