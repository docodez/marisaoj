#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1};
int dy[] = {1, 0};

int a[5][5];

int ans = 0;
void go(int x, int y, int s) {
	s += a[x][y];
	ans = max(ans, s);
	for (int i = 0; i < 2; ++i) {
		if (x + dx[i] <= 4 && y + dy[i] <= 4) go(x + dx[i], y + dy[i], s);
	}
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			cin >> a[i][j];
		}
	}
	go(1, 1, 0);
	cout << ans;
	return 0;
}
