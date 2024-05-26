#include <bits/stdc++.h>
using namespace std;

int n;
int a[15][15];
int mnCost = 1e9 + 7;
bool vis[15];

void go(int i, int cnt, int cost, int s) {
	if (cnt == n) {
		mnCost = min(mnCost, cost + a[i][s]);
	}
	for (int j = 1; j <= n; ++j) if (j != i && j != s && !vis[j]) {
		if (cost + a[i][j] <= mnCost) {
			vis[j] = true;
			go(j, cnt + 1, cost + a[i][j], s);
			vis[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) go(i, 1, 0, i);
	cout << mnCost;
	return 0;
}
